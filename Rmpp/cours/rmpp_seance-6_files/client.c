#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

int
main (int argc, char *argv[])
{
  int sfd;
  int port;
  struct hostent *host;
  struct sockaddr_in addr;
  int srv;
  uint8_t c, buf[512];
  int len;

  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "error: gethostbyname");
    exit(1);
  }

  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd < 0) {
    perror("socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = *((uint32_t *) host->h_addr);
  addr.sin_port = htons(atoi(argv[2]));

  if (connect(sfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
    perror("connect");
    exit(1);
  }

  while ((len = read(fileno(stdin), buf, sizeof(buf))) > 0) {
    if (write(sfd, buf, len) < 0) {
      perror("write");
    }
  }

  close(sfd);

  return 0;
}
