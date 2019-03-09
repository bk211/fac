#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

int
main (int argc, char *argv[])
{
  int server;
  int port;
  struct sockaddr_in addr;
  int client;
  uint8_t buf[1024];
  int len;


  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[1]);

  server = socket(AF_INET, SOCK_STREAM, 0);
  if (server < 0) {
    perror("socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(server, (struct sockaddr *) &addr, sizeof(addr)) < 0)  {
    perror("bind");
    exit(1);
  }

  if (listen(server, 8) < 0)  {
    perror("listen");
    exit(1);
  }

  if ((client = accept(server, NULL, 0)) < 0) {
    perror("accept");
    exit(1);
  }
  printf("ouverture de session\n");

  for (;;) {
    bzero(buf, sizeof(buf));
    if ((len = read(client, buf, sizeof(buf))) < 0) {
      perror("read");
    }
    printf("données reçues\n");
    if (len == 0) {
      printf("fermeture de session\n");
      break;
    }
    if (write(client, buf, len) < 0)  {
      perror("write");
    }
    printf("données renvoyées\n");
  }

  close(client);
  close(server);

  return 0;
}
