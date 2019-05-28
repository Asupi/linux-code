#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    
    while(cin>>a>>b)
        cout<<(a*b)/gcd(a,b);

    return 0;
}
