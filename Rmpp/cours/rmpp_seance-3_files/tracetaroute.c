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

int
main (int argc, char *argv[])
{
  pid_t pid;

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
    printf("Hello from child!\n");
  }
  else {
    printf("Hello from parent!\n");
  }

  return 0;
}
