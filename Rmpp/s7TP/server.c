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
	struct sockaddr_in addr,cli;
    int server, client;

    int port;
    socklen_t len;
    int peer;
    uint8_t buf[1024];

	port = atoi(argv[1]);
	server = socket(AF_INET,SOCK_STREAM ,0);
	client= socket(AF_INET,SOCK_STREAM ,0);
	if (server <0)
	{
		perror("socket");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(argc ==2){
		if(bind(server, (struct sockaddr *)&addr, sizeof addr)<0){
        perror("bind");
        exit(1);
    	}

        if((listen(server,8)<0)){
            perror("listen");
        	exit(1);
        }
        len = sizeof(cli);

        peer=accept(server,(struct sockaddr *)&cli, &len);
        if (peer <0){
        perror("accept");
        exit(1);
    	}

    	for (;;) { 
        bzero(buf,sizeof buf); 
        read(server, buf, sizeof(buf)); 
        bzero(buf,sizeof buf); 
        int n = 0; 
        while ((buf[n++] = getchar()) != '\n') ; 
        write(server, buf, sizeof(buf)); 
    	} 


    }
	
	close(server);
	return 0;
}