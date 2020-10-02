#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define repi(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define M 1000000007
#define INF 1e18

using namespace std;

int main()
{
    ios;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        set<ll> v;
        repi(i, n)
        {
            ll x;
            cin >> x;
            v.insert(x);
        }
        n = v.size();
        if (k == 1)
        {
            if (n > 1)
                cout << (-1) << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            cout << (1 + max((ll)0, (n - 2) / (k - 1))) << endl;
        }
    }
    return 0;
}