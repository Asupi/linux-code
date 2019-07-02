#include<iostream>
#include<string>
using namespace std;

int get_root(int s)
{
    if(s<10)
    {
        return s;
    }
    int sum=0;
    while(s>0){
        sum+=s%10;
        s/=10;
    }
    if(sum>=10)
    {
        sum=get_root(sum);
    }
    return sum;
}
int main()
{
    string s;
    while(cin>>s){
        int sum=0;
        for(int t=0;t<s.size();++t){
            sum+=s[t]-'0';
        }
        sum =get_root(sum);
        cout<<sum<<endl;
    }
}
