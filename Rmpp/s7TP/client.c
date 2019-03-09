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
	struct sockaddr_in addr;
    int server, client;

    int port;
    int len;
    uint8_t buf[1024];

    if (argc != 3)
    {
        printf("Usage:%s [host] port\n", argv[0] );
		exit(1);
    }
    
    port = atoi(argv[1]);
	client = socket(AF_INET,SOCK_STREAM ,0);
	if (client <0)
	{
		perror("socket");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(argc ==3){
		if(connect(client, (struct sockaddr *)&addr, sizeof addr)<0){
        perror("connect");
        exit(1);
   		}

   		for (;;) { 
        bzero(buf, sizeof(buf)); 
        int n = 0; 
        while ((buf[n++] = getchar()) != '\n') ; 
        write(client, buf, sizeof(buf)); 
        bzero(buf, sizeof(buf)); 
        read(client, buf, sizeof(buf)); 
    	}
	}
    close(client);

	return 0;
}