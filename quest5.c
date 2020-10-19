#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status;
    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
        char inp[100];                                                    
        char* argsv[] ={ NULL };                                                
        printf("Enter path of program with linker libraries:");  
        gets(inp);                        
        char* pass;
        int index=0;
        int execute;
        argsv[index]="gcc";                                                 
        index++;
        pass=strtok(input," ");
        while(pass != NULL)
        {
           argsv[index] = pass;
           printf("%s ",pass);
           [pass]= strtok(NULL, " ");
           index++; 
        }
        
        argsv[index]= NULL;                                                 
        execute = execv("/usr/bin/gcc",argsv);                              
        if(execute<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status,0); 
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
		
    }
    return 0;

}