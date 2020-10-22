// http://codeforces.com/contest/455/problem/A
// A. Boredom
// File Creation Date: 22-Oct-2020
// Author: Lucas Pavanelli (https://github.com/pavalucas)

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll freq[100010];
ll dp[100010];

int main()
{
    int n;
  cin >> n;
  ll maxNum = 0;
  for(int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    freq[a]++;
    maxNum = max(maxNum, a);
  }

  dp[0] = 0;
  for(int i = 1; i <= maxNum; i++) {
    dp[i] = max(dp[i], dp[i-1]);
    ll val = freq[i] * i;
    if(i > 1) {
      val += dp[i-2];
    }
    dp[i] = max(dp[i], val);
  }
  cout << dp[maxNum] << '\n';
}