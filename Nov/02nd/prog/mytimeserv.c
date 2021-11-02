#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 511

int main(int argc,char* argv[])
{
	struct sockaddr_in servaddr,cliaddr;
	int s,nbyte,addrlen = sizeof(struct sockaddr);
	char buf[MAXLINE+1]="my day time\n";
	if(argc!=2)
	{
		printf("usage: %s port\n",argv[0]);
		exit(0);
	}
	if((s=socket(PF_INET,SOCK_DGRAM,0))<0)
	{
		perror("socket fail");
		exit(0);
	}
	bzero((char*)&servaddr,addrlen);
	bzero((char*)&cliaddr,addrlen);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));
	if(bind(s,(struct sockaddr *)&servaddr,addrlen)<0)
	{
		perror("bind fail");
		exit(0);
	}
	while(1)
	{
		printf("%s",buf);
		puts("Server : waiting request.");
		nbyte = recvfrom(s,NULL,0,0,(struct sockaddr *)&cliaddr,&addrlen);
		if(sendto(s,buf,strlen(buf),0,(struct sockaddr *)&cliaddr,addrlen)<0)
		{
			perror("sendto fail");
			exit(1);
		}
		puts("sendto compelte");
	}
	return 0;
}