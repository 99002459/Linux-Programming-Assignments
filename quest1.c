#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int fd1,size;
	fd =open("Input.csv",O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=300;
	char buff[maxlen];
	size=read(fd,buff,maxlen);
	if(size<0)
	{
		perror("read");
		exit(2);
	}
    int fd2,sizef;
	fd2=open("sample.csv",O_WRONLY|O_CREAT, 0666);
	if(fd2<0)
	{
		perror("open");
		exit(3);
	}
	sizef =	write(fd2, buff, maxlen);
    if(sizef<0)
	{
		perror("write");
		exit(4);
	}
    close(fd1);
    close(fd2);
    printf("Copy Successful \n");
}
