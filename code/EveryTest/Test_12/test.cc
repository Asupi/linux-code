#include<iostream>
#include<cmath>
using namespace std;

bool sushu(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return false;
        
    }
    return true;

}
int main()
{
    int n;
    while(cin>>n)
    {
        int half=n/2;
        int num1,num2;    
            for(int i=half;i>0;i--)
            {
                if(sushu(i) && sushu(n-i))
                    num1=i;
                    num2=n-i;
                    break;
            }
            cout<<num1<<endl;
            cout<<num2<<endl;
    }
    return 0;
}
