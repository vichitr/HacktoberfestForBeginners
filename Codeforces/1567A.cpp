#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {res += 'D';}
        else if (s[i] == 'D') {res += 'U';}
        else {res += "LR"; i++;}
    }
    cout << res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    //solve();
}
