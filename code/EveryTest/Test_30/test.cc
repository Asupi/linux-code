#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    char tab[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string s;
    while(getline(cin,s))
    {
        int i,j;
        for(i=0;i<s.size();i++)
        {
             if(s[i]=' ')
             {
                 cout<<' ';
             }
             else{
                 for(j=0;j<26;j++)
                 {
                     if(s[i]=tab[j]) break;
                 }
                 if(j>=5){
                     cout<<tab[j-5];
                 }
                 else{
                     cout<<tab[j+21];
                   }   
             }
        }
        cout<<endl;
    }
    return 0;
}
