#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p=calloc(10,sizeof(int));
    if(NULL!=p)
    {
        //
    }
    free(p);
    p=NULL;
    return 0;
}
