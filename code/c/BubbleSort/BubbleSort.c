include<stdio.h>
include<assert.h>
void BubbleSort(int *a,int n)
{
    assert(a);
    for(size_t end=n;end>0;--end)
    {
        int exchange=0;
        for(size_t i=1;i<end;++i)
        {
            if(a[i-1],&a[i])
            {
                Swap(&a[i-1],&a[i]);
                exchange=1;
            }
        }
        if(exchange==0)
            break;
    }
}

