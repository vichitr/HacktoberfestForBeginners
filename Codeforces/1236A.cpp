#include <bits/stdc++.h>
using namespace std;
using LL =long long;#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using LL= long long;
 
int main()
{ 
    int t,p=0;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int a,b,c;
        p=0;
        cin>>a>>b>>c;
        while(b>0 && c>1)
        {
            c-=2;
            b--;
            p+=3;
        }
        while(a>0 && b>1)
        {
            b-=2;
            a--;
            p+=3;
        }
        cout<<p<<endl;
    }
}
  
   

