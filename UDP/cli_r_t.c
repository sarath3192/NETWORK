#include "header.h"
int main(int argc,char **argv)
{
	if(argc!=5)
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
	v2.sin_family=AF_INET;
	v2.sin_port=htons(atoi(argv[3]));
	v2.sin_addr.s_addr=inet_addr(argv[4]);
	len=sizeof(v1);
	printf("enter the data\n");
	gets(s);
	b=sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&v1,len);
	if(b<0)
	{
		perror("sendto:");
		return 0;
	}
	r=recvfrom(sfd,s,sizeof(s),0,(struct sockaddr*)&v2,&len);
	if(r<0)
	{
		perror("recvform:");
		return 0;
	}
         printf("%s\n",s);
	close(sfd);
}
