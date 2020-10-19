#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd,nbytes;
	fd=open("Input.csv",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int len=100;
	char buff[len];
	nbytes=read(fd,buff,len);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    buff[len]='\0';
    printf("%s\n",buff);
    close(fd);
}
