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

int copy(int src, int dst){
	
}


int main(int argc, char const *argv[])
{
	struct sockaddr_in addr;
	int sock, remote;
	uint8_t buf[1024];
    if(argc < 2 || argc > 3){
    {	
        printf("Usage:%s [host] port\n", argv[0] );
		exit(1);}
    }

   	sock= socket(AF_INET,SOCK_STREAM ,0);
   	if(sock <0){
		perror("socket");
		exit(1);
	}

	if(argc ==2){//mode server
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY;
		addr.sin_port = htons(atoi(argv[1]));
	
		if (bind (sock,(struct sockaddr*) &addr,sizeof addr)<0)
		{
			perror("bind");
			exit(1);
		}

		if (listen(sock,8)<0)
		{
			perror("listen");
			exit(1);
		}

		if ((remote = accept(sock,NULL,NULL))<0)
		{
			perror("accept");
			exit(1);
		}

		close(sock);
	}

	else{//mode client
		struct hostent *host;
		if((host = gethostbyname(argv[1]))==NULL){
			perror("gethostbyname");
			exit(1);
		}

		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = *((uint32_t *) host->h_addr);
		addr.sin_port = htons(atoi(argv[2]));

		if (connect(sock,(struct sockaddr *) &addr,sizeof addr)<0)
		{	
			perror("connect");
			exit(1);
		}

		remote = sock;
	}

//	write(remote,"COUCOU",7);


	return 0;
}











