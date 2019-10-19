#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#define MAXN 100001



  int main()
   {
     FastRead
  
     ll n,i;
     cin>>n;
     ll a[n],x=1,y=1;
     for(i=0;i<n;i++)
     {
      cin>>a[i];
      if(a[i]==0)
        x=i+1;
      else
       if(a[i]==1)
        y=i+1;
     }
     cout<<min(x,y)<<"\n";
    return 0;
   }
