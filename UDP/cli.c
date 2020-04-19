#include "header.h"
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage:./ser port ipaddres\n");
		return 0;
	}

	int sfd,b,len,r;
	char s[20];
	struct sockaddr_in v1,v2;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0)
	{
		perror("socket:");
		return 0;
	}

	v1.sin_family=AF_INET;
	v1.sin_port=htons(atoi(argv[1]));
	v1.sin_addr.s_addr=inet_addr(argv[2]);
	len=sizeof(v1);
	printf("enter the data\n");
	gets(s);
	b=sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&v1,len);
	if(b<0)
	{
		perror("sendto:");
		return 0;
	}
	close(sfd);
}
