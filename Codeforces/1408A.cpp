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
        ll n;
        cin >> n;
        vector<vector<ll>> a(3, vector<ll>(n));
        repi(i, n) cin >> a[0][i];
        repi(i, n) cin >> a[1][i];
        repi(i, n) cin >> a[2][i];
        ll cur = 0;
        vector<ll> ans(n);
        ans[0] = a[0][0];
        rep(i, 1, n - 1)
        {
            if (a[cur][i] == a[cur][i - 1])
                cur = (cur + 1) % 3;
            ans[i] = a[cur][i];
        }
        if (ans[0] == ans[n - 1])
        {
            repi(i, 3) if (a[i][0] != ans[n - 1] && a[i][0] != ans[1])
            {
                ans[0] = a[i][0];
                break;
            }
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}