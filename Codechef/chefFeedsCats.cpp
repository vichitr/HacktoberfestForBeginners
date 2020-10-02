#include<iostream>

using namespace std;

int main()

{

    int n,m,t,i,check,j;

    cin>>t;

    while(t--)

    {
 
       check=1;
 
       cin>>n>>m;

       int fo[m];

       int c[n];
       for(i=0;i<m;i++)
 
       cin>>fo[i];
    
       for(i=0;i<m;i++)
    
       {

            for(j=1;j<=n;j++)

            {
   
             if(fo[i]==j)

                c[j]++;
  
             }
  
      }
    
    int count=c[0];
   
    for(j=1;j<=n;j++)

        {
  
      if(c[j]>count&&c[j]!=0)

        check=0;
 
       }
 
       if(check==0)
  
       cout<<"NO";
 
       else
  
       cout<<"YES";

    }
  
  
}