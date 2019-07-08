#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>


void *rout(void *arg)
{   
   int i;
   for(i=1;i<10;++i)
   {
       printf("This is a pthread\n");
       sleep(1);
   }

}
int main()
{
    pthread_t tid,tid1,tid2;
    
    pthread_create(&tid,NULL,rout,NULL);
    pthread_create(&tid1,NULL,rout,NULL);
    pthread_create(&tid2,NULL,rout,NULL);
    pthread_cancel(tid);
    pthread_cancel(tid1);
    pthread_cancel(tid2); 
    pthread_join(tid,NULL); 
    pthread_join(tid1,NULL); 
    pthread_join(tid2,NULL);
    return 0;
}
