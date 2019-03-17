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

int main(int argc, char const *argv[])
{
	int server, client;
	int port;
	struct sockaddr_in addr;
	uint8_t buf[1024];
	int len;

	if (argc != 2)
		{
			fprintf(stderr, "%s\n", argv[0]);
			exit(1);
		}	
	port = atoi(argv[1]);
	server = socket(AF_INET,SOCK_STREAM ,0);
	if (server <0)
	{
		perror("socket");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server, (struct sockaddr *) &addr, sizeof addr) <0)
	{
		perror("bind");
		exit(1);
	}

	if (listen(server, 8) <0)
	{
		perror("listen");
		exit(1);
	}

	if ((client= accept(server,NULL,NULL))<0)
	{
		perror("accept");
		exit(1);
	}

	printf("Session ouverte\n");
	for (;;)
	{
		bzero(buf,sizeof buf);
		if ((len = read (client, buf,sizeof buf))<0)
		{
			perror("read");		
		}

		printf(">Donne recue\n");
		if (len == 0){
			printf("Session ferme\n");
			break;
		}

		if (write(client,buf, len ) <0)
		{
			perror("write");
		}

		printf("Donees renvoye\n");

	}


	close(client);
	close(server);
	printf("Session ferme\n");
	return 0;
}