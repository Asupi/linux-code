#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a[100002]={0};
    a[0]=1;
    a[1]=1;
    for(int i=2;i<100002;i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(a[i]/1000000>0)
        {
            a[i]=a[i]%1000000;
        }
    }
    int n;
    while(cin>>n)
    {
        if(n<37)
            cout<<a[n]<<endl;
        else{
            cout<<setfill('0')<<setw(6)<<a[n]<<endl;
        }
    }
    return 0;
}
