#include<iostream>

#include<math.h>

using namespace std;


int main()

{

    int n,t;

    cin>>t;

    while(t--)
  
  {

    cin>>n;
 
   int c=0,i;
   
   while(n)

    {
 
    i=sqrt(n);

    n=n-(i*i);
  
    c++;

    }
 
   cout<<c<<endl;

    }
   
 return 0;

}