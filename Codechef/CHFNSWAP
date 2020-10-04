//author: kvv1618
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll s=n*(n+1)/2;
	    if(s%2!=0)
	    {
	        cout<<0<<endl;
	        continue;
	    }
	    ll ans=((ll)(sqrt(4*s+1)-1))/2;
	    if (sqrt(4*s+1) == (ll)sqrt(4*s+1))
	    {
	        ll a2=n-ans;
	        ans=(ans*(ans-1)/2)+((a2)*(a2-1)/2)+a2;
	    }
	    else
	    {
	        ans=n-ans;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
/*
# cook your dish here
import math
def nc2(n):
    return (n*(n-1))//2

for t in range(int(input())):
    n=int(input())
    total = (n*(n+1))//2
    if(total & 1):
        print(0)
    else:
        ans=round(((math.sqrt(4*total+1)-1))//2)
        if math.sqrt(4*total+1)==int(math.sqrt(4*total+1)):
            ans2=n-ans
            ans=nc2(ans)+nc2(ans2)+ans2
        else:
            ans=n-ans
        print(ans)*/
