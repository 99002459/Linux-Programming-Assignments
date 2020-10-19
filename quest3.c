#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int* fd;
    int nbytes;
	char ch;
    int word_cnt=0;
    int char_cnt=0;
    int line_cnt=0;
    fd=fopen("Input.csv",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    for (ch = getc(fd); ch != EOF; ch = getc(fd)) 
    {
        char_cnt++;
        if (ch == '\n') // Increment count if this character is newline 
            line_cnt++;
        if (ch == ' ' | ch == ',')
            word_cnt++;
    }
    printf("cc = %d,wc = %d,lc = %d",char_cnt,word_cnt,line_cnt);    
}