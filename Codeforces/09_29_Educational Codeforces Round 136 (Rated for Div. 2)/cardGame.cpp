#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define lli long long int
#define ld long double
#define pb push_back

ll mod = 998244353;
// CODE START

ll NCR(ll num, ll re) {
    ll p = 1, k = 1;
    if (num - re < re)
        re = num - re;
    if (re != 0) {
        while (re) {
            p *= num;
            k *= re;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            num--;
            re--;
        }
    }

    else
        p = 1;
    return p;
}

void helper(int i, vector<vector<ll>>& dp) {
    if (i == 2) {
        return;
    }

    helper(i - 2, dp);

    dp[i][0] = (NCR(i - 1, i / 2) + dp[i - 2][1]) % mod;
    dp[i][1] = (NCR(i - 2, i / 2) + dp[i - 2][0]) % mod;
    dp[i][2] = (dp[i - 2][2]) % mod;
}

void solveITcaptain() {
    int n;
    cin >> n;
    // Sequence of Turns: Alex Boris     Boris Alex      Alex Boris     Boris Alex
    vector<vector<ll>> dp(n + 1, vector<ll>(3, -1));
    // Alex Wins
    dp[2][0] = 1;
    // Boris Wins
    dp[2][1] = 0;
    // Draw
    dp[2][2] = 1;

    // helper(n, dp);
    for(int i=4; i<=n; i+=2) {
        dp[i][0] = (NCR(i - 1, i / 2) + dp[i - 2][1]) % mod;
        dp[i][1] = (NCR(i - 2, i / 2) + dp[i - 2][0]) % mod;
        dp[i][2] = (dp[i - 2][2]) % mod;
    }

    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << "\n";
}

// CODE END


int main() {
    system("cls");
    ios_base::sync_with_stdio(false);    cin.tie(nullptr);     cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solveITcaptain();
    }
    return 0;
}