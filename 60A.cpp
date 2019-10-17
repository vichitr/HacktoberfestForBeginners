#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#define MAXN 100001

  int main()
   {
     FastRead
     
      ll n,m,i,j,k;
      cin>>n>>m;
      string p,s;
      int t;
      i=1,j=n;
      while(m--)
      {
        cin>>p>>p>>s>>p>>t;
        if(s=="left")
        {
          if(j>t-1)
            j=t-1;
        }
        else
          if(s=="right")
        {
          if(i<t+1)
            i=t+1;
        }
      }
      if(i>j)
        cout<<-1;
      else
        cout<<j-i+1;
        
      
    return 0;
   }
