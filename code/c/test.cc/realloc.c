#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=malloc(100);
    if(ptr!=NULL)
    {
          //
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    ptr=realloc(ptr,1000);
    int*p=NULL;
    p=realloc(ptr,1000);
        if(ptr!=NULL)
        {
           ptr=p;
        }
    free(ptr);
    return 0;
}
