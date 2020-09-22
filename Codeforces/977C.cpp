#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define ld  long double
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
const ll maxn=1e5+2;
const ll mod=3e18;

int main(){
	fast;
	ll n,k,i,j;
	cin>>n>>k;
	ll a[n];
	for(ll &i : a)
		cin>>i;
	sort(a,a+n);

	ll l=1,r=1e9,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		int it  = (upper_bound(a,a+n,mid)-a);
		if(it>k)
			r=mid-1;
		else{
			if(it==k)
				ans=mid;
			l=mid+1;
		}
			
	}
	
	if(ans>1e9)
		ans=-1;
	cout<<ans<<endl;
	
}