#include<iostream>    
#include<string>
#include<vector>
using namespace std;
vector<string>vec;
bool  lexicographically()
{
    int i=0;
    string s;
    while((i+1)<vec.size())
    {
        if(vec[i].compare(vec[i+1])>0)
            return 0;
    }
    return 1;
}
bool Lenths()
{
    int i=0;
    while((i+1)<vec.size())
    {
        if(vec[i+1].size()<vec[i].size())
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    string s;
    int n,i=0;
    bool b1,b2;
    cin>>n;
    while(i<n)
    {
        cin>>s;
        vec.push_back(s);
        i++;
    }
    b1= lexicographically();
    b2=Lenths();
    if(b1 &&b2)
    
        cout<<"both";
    else if(b1 && !b2)
        cout<<" lexicographically";
    else if(!b1&&b2)
        cout<<"Lenths";
    else
        cout<<"none";
    return 0;
}  
