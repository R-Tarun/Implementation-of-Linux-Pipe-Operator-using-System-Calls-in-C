#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include<errno.h> 
#include<sys/wait.h> 
#include <unistd.h> 
int main(int argc, char *argv[]){ 
  
    
    int a[2]; 
    pipe(a); 
  
    if(!fork()) 
    { 
        close(1); 
          
        dup(a[1]); 
          
        close(a[0]); 
          
        execlp(argv[1],argv[1],NULL); 
    } 
    else
    { 
        close(0); 
          
        dup(a[0]); 
          
        close(a[1]); 
          
        execlp(argv[2],argv[2],NULL); 
    } 
} 
 
