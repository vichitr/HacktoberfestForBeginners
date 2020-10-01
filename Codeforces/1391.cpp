#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res % mod * a % mod) % mod;
        b /= 2;
        a = (a % mod * a % mod) % mod;
    }
    return res;
}
 
ll fact[1000005], dp[1000005];
 
 
void solve() {
    ll n;
    cin >> n;
    cout << dp[n] << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    boost
    ll t = 1;
    // cin >> t;
    while (t--) {
        fact[3] = 6, dp[3] = 2;
        for (ll i = 4; i <= 1000005; i++) {
            fact[i] = (fact[i - 1] % mod * i % mod) % mod;
            dp[i] = (fact[i] % mod - ( (2) % mod * (fact[i - 1] % mod - dp[i - 1] % mod + mod) % mod ) % mod + mod) % mod;
        }
        solve();
    }
    return 0;
}
