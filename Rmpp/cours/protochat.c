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
#include <arpa.inet>
#define MAX_CLIENTS 2;

int sendall(int fd , void* buf, int *len){
	int sent_len = 0;
	uint_8 *b = buf;
	int n;

	while (sent_len < *len){
		n = write(fd, b + sent_len, *len - sent_len);
		if(n<0){
			break;
		}
		sent_len += n;
	}
	if (n<0){
		*len = sent_len;
		return -1;
	}

	return 0;
}
/*
int sendall(int fd , void* buf, int *len){
	int i=0,n;
	void * temp;
	while(i < *len){
		if((n=write(fd, buf+i,1))< 0){
			*len = sizeof n;
			return -1;
		}
		i++

	}
	return 0;

}*/

int open_tcp_listener(const char *port)
{
	struct addrinfo hints, *addrinfo,*ai;
	int n, srv, ret;
	char ipstr[INET6_ADDRSTRLEN];

	hints.ai_family =AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((n= getaddrinfo(NULL, port, &hints, &addrinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n",gai_strerror(n) );
		exit(1);
	}

	for (ai = addrinfo; ai != NULL; ai = ai->ai_next)
	{
		inet_ntop(ai->ai_family,&((struct sockaddr *)ai->ai_addr)->sin_addr, ipstr, sizeof ipstr);
		printf("Trying to listen on %s n port %s...\n",ipstr,port);

		if ((srv= socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol))< 0)
		{
			perror("socket");
		}

		if (setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int))< 0)
		{
			perror("setsockopt");
		}

		if (fcntl(srv,F_SETFL, O_NONBLOCK)<0)
		{
			perror("fcntl");
			exit(1);
		}

		if (listen(srv,8)<0)
		{
			perror("listen");
			exit(1);
		}

		ret = srv;
		printf("Listening on %s on port %s\n", ipstr, port);


	}

	freeaddrinfo(addrinfo);
	return ret;


}
int main(int argc, char const *argv[])
{
	int i,srv,fd,j,n;
	int len;
	srtuct sockaddr_storage addr;
	int addrlen;
	struct pollfd fds[MAX_CLIENTS];
	int nfds;
	uint_8 buf[2048];

	if (argc != 2)
	{
		fprintf(stderr, Usage..."%s\n",argv[0] );
		exit(1);
	}

	if((srv = open_tcp_listener(argv[1]))< 0){
		fprintf(stderr, "could not listen in ip4 / ip6%s\n", );
		exit(1);
	}

	bzero(fds,sizeof fds);
	fds[0].fd= srv;
	fds[0].events= POLLIN;
	nfds = 1;

	for (;;)
	{
		if ((n = poll(fds, nfds, 30000)) <0)
		{
			perror("poll");
			exit(1);
		}

		else if(n == 0){
			if(nfds == 1){
				break;
			}
		}

		if ((fds[0].revents & POLLIN)==0){
			if((fd = accept(srv,NULL,NULL))<0){
				if(errno == EWOULDBLOCK){
					fprintf(stderr, "accept EWOULDBLOCK\n");
				}
			}

			fprintf(stderr, "New connection with fd = %d\n", fd);
			if(nfds == MAX_CLIENTS){
				write(fd,"Sorry, server full!",20);
				fprintf(stderr, "Server full, closing connection with fd = %d\n",fd );
				close(fd);
			}
			fds[nfds].fd=fd;
			fds[nfds].events = POLLIN;
			nfds++;

		}

		for (i = 0; i < nfds; ++i)
		{
			if ((fds[i].revents & POLLIN)==0) continue;

			fprintf(stderr, "message from fd: %d\n", fds[i].fd);
			bzero(buf,sizeof buf);
			if ((len = read(fds[i].fd,buf,sizeof(buf)))< 0)
			{
				perror("read");	
			}
			else if(len == 0){
				fprintf(stderr, "Disconnect from client with fd = %d\n", fds[i].id);
				close(fds[i].fd);

				for (j = i+1; i < ; ++j){
					
				}
			}

			else{
				for (j = 1; j < nfds; ++j)
				{
					if (fds[j].fd == fds[i].fd) continue;
					n= len;
					if (sendall(fds[j].fd,buf,&len)<0)
					{
						fprintf(stderr, "sendallL only sent %d of %d bytes\n",len,n );
					}
				}
			}
		}
	}

	return 0;
}