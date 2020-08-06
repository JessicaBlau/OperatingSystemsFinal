#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char* argv[])
{
    if (kill(atoi(argv[1]), 0) == -1){
        if(errno == EPERM){
            printf ("Process %s exists but we have no permission\n", argv[1]);
            return 0;
        }
        printf ("The process %s doesn't exist\n", argv[1]);
    }
    else{
        printf ("process %s exists\n", argv[1]);
    }
    
    return 0;
}