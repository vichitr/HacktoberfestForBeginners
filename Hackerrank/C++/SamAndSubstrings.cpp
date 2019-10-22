#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
// Utility method to covert character digit to
// integer digit
int toDigit(char ch)
{
    return (ch - '0');
}
int substrings(string s) {
    int MOD=1000000007;
    int l=s.length();
    long long int res = 0;
    long long int f = 1;
    for(int i = l-1; i >= 0; i--) {
        res = (res + (s[i]-'0')*f*(i+1)) % MOD;
        f = (f*10+1) % MOD;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
