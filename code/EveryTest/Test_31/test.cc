#include<iostream>
using namespace std;
int main()
{
    int a=0,i=0;
    while(cin>>a)
    {
        cout<<a<<"=";
        i=2;
        while(1)
        {
            if(a%i==0)
            {
                cout<<i;
                a=a/i;
                break;
            }
            i++;
        }
        while(a!=1)
        {
            while(i)
            {
                if(a%i==0)
                {
                    cout<<"*"<<i;
                    a=a/i;
                    break;
                }
                i++;
            }
        }
        cout<<endl;
    }
    return 0;

}
