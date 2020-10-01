// author : hrahul2605
#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long
#define f first
#define se second
#define LB lower_bound
#define UB upper_bound
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pie 3.14159265358979323846264338327950288
const unsigned int MOD = 1000000007;
 
using namespace std;
 
int32_t main()
{
    IOS;int T;T=1;
    cin>>T;
    while(T--)
    {
        ll n,a,b;cin>>n;
        ll  m = n - 1 ;
        if(!(n%2)){
            a = b = n / 2 ;
        } else {
            for(int i = 3; i <= sqrt(n) ; i += 2){
                if(n%i == 0){
                    ll x = max ( n - i , i ) , y = min ( n - i , i );
                    if(x % y == 0) 
                        m = min(x , m ) ;
                    ll z = n / i;
                    x = max ( n - z , z ) , y = min ( n - z , z );
                    if(x % y == 0) 
                        m = min(x , m ) ;
                }
            }
 
            a = m ; b = n - m;
        }
        cout<<a<<" "<<b<<"\n";
    }
 
    return 0;
}