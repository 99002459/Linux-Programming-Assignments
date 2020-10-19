#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
  
int main() 
{ 
  
    struct rlimit limit; 
    //Get limits andd print
    if( getrlimit(RLIMIT_NOFILE, &limit) == 0) 
        printf("soft limit= %ld \t"
           " hard limit= %ld \n", limit.rlim_cur,  
                                 limit.rlim_max); 
    else
        fprintf(stderr, "%s\n", strerror(errno)); 
      

    return 0; 
} 