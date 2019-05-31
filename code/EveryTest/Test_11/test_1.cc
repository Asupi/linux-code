#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    while(a!=b)
    {
        if(a>b)
          a/=2;
        else
          b/=2;
        
    }
    cout<<a<<endl;
    return 0;
}
