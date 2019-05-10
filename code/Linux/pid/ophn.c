#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t ret=fork();
    if(ret<0)
    {
        perror("fork");
        return 1;
    }
    else if(ret==0)
    {
        printf("child,pid:%d\n",getpid());
        sleep(10);
    }
    else
    {
        printf("father,pid:%d\n",getpid());
        sleep(3);
        exit(0);
    }
    return 0;
}

    
