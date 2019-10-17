#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;


int main()
{
  FastRead
  ll n,k,t,ans;
  cin>>n>>k;
  t=sqrt(8*n+8*k+9);
  if(2*n+3>=t)
  ans=((2*n+3)-t)/2;
  else
  ans=((2*n+3)+t)/2;

cout<<ans<<"\n";

 return 0;
}
