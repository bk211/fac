#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <errno.h>

uint16_t
icmp_checksum (void *buf, uint32_t len)
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

void icmp_request_echo(struct sockaddr *addr){
  int sock;
  int cnt;
  int len;
  struct icmphdr icmp;

  icmp.type = ICMP_ECHO;
  icmp.cpde =0;
  icmp.un.echo.id = getppid();
  icmp.un.echo.sequence = 0;
  icmp.check_sum = 0;
  icmp.check_sum = check_sum(&icmp, sizeof icmp);

  sock = socket(AF_INET,SOCK_RAW, IPPROTO_ICMP);
  if (sock == -1){
    perror ( *(listen) socket*);
    exit(1);
  }
  for (cnt = 1; cnt < 64; ++cnt)
  {
    if (setsockopt(sock,SOL_IP,IP_TTL,&cnt, sizeof(cnt))<0){
      perror("setsockopt");    
    }
    if (sento(sock,&icmp, sizeof(icmp),0,addr,sizeof(*addr))<0){
      perror("sento");
    }

    sleep(1);
  }


}


void icmp_listen(pid_t pid){
  int sock;
  char[1024] name;
  sock = socket(AF_INET,SOCK_RAW, IPPROTO_ICMP);
  if (sock == -1){
    perror ( *(listen) socket*);
    exit(1);
  }
  for (int i = 0; i < 64; ++i)
  {
    bzero(buf,sizeof(buf));

    len = recv(sock,buf,sizeof buf,0);
    if (len<0){
      perror("(listen) recv")
    }
    else if(len == 0){
      printf("Connection closed\n");
    }

    ip = (struct iphdr *) buf;
    icmp = (struct icmphdr *) (buf + ip->ihl*4);
    if (icmp-> un.echo.id != getpid()){
      i--;
      continue;
    };
    addr.sin_family =AF_INET;
    addr.sin_addr.s_addr = ip->saddr;
    
    if(getnameinfo((struct sockaddr*) &addr, sizeof(addr),name,sizeof name,NULL,0 ,0) != 0){
      printf("getnameinfo error\n");
    }
    printf("%s\t%s\n", );

    printf("%s\n",inet_ntoa((struct in_addr) {ip->saddr}));

    if(icmp-> type == ICMP_ECHOREPLY){
      printf("Arrived\n");
      kill(pid,SIGINT);
      return;
    }
  }

}



int
main (int argc, char *argv[])
{
  pid_t pid;
  struct hostent *host;
  struct sockaddr_in *addr;

  if (argc < 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);

  if (host == NULL) {
    printf("error gethostbyname");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = 0;
  addr.sin_addr.s_addr = *((uint32_t *) host->h_addr);
  printf("Traceroute for %s (%s)\n",argv[1],inet_ntoa(addr.sin_addr) );

  if (argc != 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    icmp_request_echo((struct sockaddr *) addr);
  }
  else {
    icmp_listen(pid)
  }

  return 0;
}
