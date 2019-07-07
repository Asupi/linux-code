#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,k,i;
    while(cin>>n)
    {
        k=0;
        int count=0;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    count++;//加count的目的是搞清楚除了几次增加代码的可读性
                }
                k++;
            }
        }
        if(n!=1)k++;
        cout<<k<<endl;
    }
    return 0;
}
