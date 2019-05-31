#include<iostream>
using namespace std;
int main()
{
   int A;
   while(cin>>A)
   {
       int k=0;
       for(k=0;A!=0;k++)
       {
          A=A&(A>>1); 
       }
       cout<<k<<endl;
   }
   return 0;
}
