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
        ll n, l;
        cin >> n >> l;
        vector<double> a(n);
        repi(i, n) cin >> a[i];
        double x = 0, y = l;
        ll i = 0, j = n - 1;
        double u = 1, v = 1;
        double ans = 0;
        while (i <= j)
        {
            if ((a[i] - x) / u <= (y - a[j]) / v)
            {
                double s = (a[i] - x) / u;
                ans += s;
                x = a[i];
                y -= s * v;
                u++;
                i++;
                if (a[j] == y)
                {
                    v++;
                    j--;
                }
            }
            else
            {
                double s = (y - a[j]) / v;
                ans += s;
                y = a[j];
                x += s * u;
                v++;
                j--;
                if (a[i] == x)
                {
                    u++;
                    i++;
                }
            }
        }
        if (y > x)
            ans += (y - x) / (u + v);
        cout << fixed << setprecision(15) << ans << endl;
    }
    return 0;
}