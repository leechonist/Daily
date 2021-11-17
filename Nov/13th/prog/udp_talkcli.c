#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 511
char* EXIT_STRING = "exit";
int recv_and_print(int sd,struct sockaddr_in addr);
int input_and_send(int sd,struct sockaddr_in addr);
int main(int argc,char* argv[])
{
	struct sockaddr_in servaddr;
	char* buf[MAXLINE];
	int s,addrlen = sizeof(servaddr);
	pid_t pid;
	if(argc != 3)
	{
		printf("Usage : %s address port\n",argv[0]);
		exit(0);
	}
	
	if((s = socket(PF_INET,SOCK_DGRAM,0))<0)
	{
		perror("socket fail");
		exit(0);
	}
	
	bzero((char*)&servaddr,sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	servaddr.sin_port = htons(atoi(argv[2]));
	
	if(sendto(s,buf,MAXLINE,0,(struct sockaddr*)&servaddr,addrlen)<0)
	{
		perror("sendto fail");
		exit(1);
	}
	puts("Server connect");
	if((pid=fork())>0) input_and_send(s,servaddr);
	else if(pid==0) recv_and_print(s,servaddr);
	close(s);
	return 0;
}
int input_and_send(int sd,struct sockaddr_in addr)
{
	char buf[MAXLINE+1];
	int nbyte,addrlen = sizeof(addr);
	while(fgets(buf,sizeof(buf),stdin)!=NULL)
	{
		nbyte = strlen(buf);
		sendto(sd,buf,nbyte,0,(struct sockaddr*)&addr,addrlen);
		if(strstr(buf,EXIT_STRING)!=NULL)
		{
			puts("Good bye.");
			close(sd);
			exit(0);
		}
	}
	return 0;
}
int recv_and_print(int sd,struct sockaddr_in addr)
{
	char buf[MAXLINE+1];
	int nbyte,addrlen = sizeof(addr);
	while(1)
	{
		if((nbyte = recvfrom(sd,buf,MAXLINE,0,(struct sockaddr*)&addr,&addrlen))<0)
		{
			perror("recvfrom fail");
			exit(1);
		}
		buf[nbyte] = 0;
		if(strstr(buf,EXIT_STRING)!=NULL) break;
		printf("%s",buf);
	}
	return 0;
}





