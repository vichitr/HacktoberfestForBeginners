#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;


int main()
{
  FastRead
  int n,a,x,b,y;
  cin>>n>>a>>x>>b>>y;

 while(a!=x && b!=y)
 {
   
   if(a<n)
    a++;
   else
    a=1;
   if(b>1)
    b--;
  else
    b=n;
  //cout<<a<<" "<<b<<"\n";
  if(a==b)
   {
    cout<<"YES"<<"\n";
    return 0;
   }
 }
 cout<<"NO"<<"\n";
  
 
 return 0;
}
