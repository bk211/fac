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
#include <poll.h>

int copy(int src, int dst){
	uint8_t buf[1024];
	int len_r,len_w;
	if((len_r = read(src,buf,sizeof buf-2))<0){
		perror("read");
		return -1;
	}
	else if(len_r ==0){
		return 0;
	}

	if( len_r == 1 && buf[0] == '\n'){
		buf[0] = '\r';
		buf[1] = '\n';
		len_r =2;
	}
	else if (buf[len_r -1]== '\n' && buf[len_r-2] != '\r'){
		buf[len_r-1]='\r';
		buf[len_r] = '\n';
		buf[len_r+1] = '\0';
		len_r++;
	}

	printf("DEBUG: %02c %02c\n",buf[len_r-1],buf[len_r] );

	if ((len_w = write(dst,buf,len_r))<0)
	{
		perror("write");
		return -1;
	}

	if (len_r != len_w)
	{
		return -1;
	}

	return len_r;
}


int main(int argc, char const *argv[])
{
	struct sockaddr_in addr;
	int sock, remote,n;
	uint8_t buf[1024];
	struct pollfd fds[2];
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
	fds[0].fd= STDIN_FILENO;
	fds[0].events = POLLIN;//|POLLOUT;
	fds[1].fd= remote;
	fds[1].events= POLLIN;//|POLLOUT;
	

	for (;;){

		if((n=poll(&fds,2,3000))<0){
			perror("poll");
			exit(1);
		}
		if (n==0) continue;
		if(fds[0].revents & POLLIN){
			if((copy(STDIN_FILENO,remote)<=0)){
				break;
			}
		}
		if(fds[1].revents & POLLIN){
			if((copy(STDIN_FILENO,remote)<=0)){
				break;
			}
		}



		if( copy(STDIN_FILENO,remote)<=0){
			break;
		}

	}
	close(remote);


//	write(remote,"COUCOU",7);


	return 0;
}











