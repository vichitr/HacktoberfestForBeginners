#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e5;

ll nn[MX+1],arr[MX+1];

int main(){
  for(ll i=1;((i*(i+1))>>1)<=MX;++i) nn[((i*(i+1))>>1)]=((i*(i+1))>>1);
  for(ll i=1,tmp=0;i<=MX;++i){
    if(nn[i]==0) nn[i]=tmp;
    else tmp=nn[i];
  }

  ll n,mx=-1e9; cin>>n;
  for(ll i=1;i<=n;++i){ cin>>arr[i]; arr[i]+=arr[i-1]; }\
  for(ll i=0;i<n;++i){ ll tmp=arr[i+nn[n-i]]-arr[i]; mx=tmp>mx?tmp:mx; }
  cout<<mx;
  return 0;
}

