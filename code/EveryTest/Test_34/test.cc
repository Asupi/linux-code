#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long arr[91];
        arr[1]=1;
        arr[2]=2;
        for(int n=3;n<=90;n++)
        {
            arr[n]=arr[n-1]+arr[n-2];
        }
        cout<<arr[n]<<endl;
    }
    return 0;
}
