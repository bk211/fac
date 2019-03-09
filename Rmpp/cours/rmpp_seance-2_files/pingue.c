#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <errno.h>

uint16_t
checksum (void *buf, uint32_t len)
{
  uint16_t *b = buf;
  uint32_t sum = 0;

  for (; len > 1; len -= 2) {
    sum += *b++;
  }
  if (len == 1) {
    sum += *((uint8_t *) b);
  }
  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  return ~sum;
}

void
display_ip_hdr (struct iphdr *ip)
{
  char src[13] = {0}, dst[13] = {0};
  strcpy(src, inet_ntoa((struct in_addr) {ip->saddr}));
  strcpy(dst, inet_ntoa((struct in_addr) {ip->daddr}));
  printf("IP packet:\n"
         "  version  : %d\n"
         "  IHL      : %d\n"
         "  ToS      : %d\n"
         "  Len      : %d\n"
         "  id       : %d\n"
         "  offset   : %d\n"
         "  TTL      : %d\n"
         "  protocol : %d\n"
         "  checksum : %d\n"
         "  source   : %s\n"
         "  dest     : %s\n",
         ip->version,
         ip->ihl,
         ip->tos,
         ip->tot_len,
         ip->id,
         ip->frag_off,
         ip->ttl,
         ip->protocol,
         ip->check,
         src,
         dst);
}

void
display_icmp_hdr (struct icmphdr *icmp)
{
  printf("ICMP datagram:\n"
         "  type     : %d\n"
         "  code     : %d\n"
         "  checksum : %d\n"
         "  echo id  : %d\n"
         "  echo seq : %d\n\n",
         icmp->type,
         icmp->code,
         icmp->checksum,
         icmp->un.echo.id,
         icmp->un.echo.sequence);
}

void
send_echo_requests (struct sockaddr *addr)
{
  int sock;
  int counter;

  struct icmphdr icmp;

  icmp.type = ICMP_ECHO;
  icmp.code = 0;
  icmp.un.echo.id = getppid();

  sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sock < 0) {
    perror("(sender) socket");
    exit(1);
  }

  for (counter = 0; counter < 8; counter++) {
    icmp.un.echo.sequence = counter;
    icmp.checksum = 0;
    icmp.checksum = checksum(&icmp, sizeof(icmp));

    if (sendto(sock, &icmp, sizeof(icmp), 0, addr, sizeof(*addr)) <= 0) {
      perror("(sender) sendto");
    }
    else {
      printf("> Sent an echo request!\n");
    }
    sleep(2);
  }
}

void
listen_echo_replies ()
{
  int sock;

  uint8_t buf[1024];
  int len;

  struct iphdr *ip;
  struct icmphdr *icmp;

  sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sock < 0) {
    perror("(listener) socket");
    exit(1);
  }

  for (;;) {
    bzero(buf, sizeof(buf));
    if (recv(sock, buf, sizeof(buf), 0) <= 0) {
      perror("(listener) recv");
    }
    else {
      ip = (struct iphdr *) buf;
      icmp = (struct icmphdr *) (buf + ip->ihl * 4);
      if (icmp->type == 0 && icmp->un.echo.id == getpid()) {
        printf("> Got an echo reply :\n");
        display_ip_hdr(ip);
        display_icmp_hdr(icmp);
        if (icmp->un.echo.sequence == 7) break;
      }
      else {
        printf("> Got something else…\n");
      }
    }
  }
}

int
main (int argc, char *argv[])
{
  pid_t pid;
  struct hostent *host;
  struct sockaddr_in addr;

  if (argc < 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  addr.sin_family = host->h_addrtype;
  addr.sin_port = 0;
  addr.sin_addr.s_addr = *((uint32_t *) host->h_addr);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    send_echo_requests((struct sockaddr *) &addr);
  }
  else {
    listen_echo_replies();
  }

  return 0;
}
