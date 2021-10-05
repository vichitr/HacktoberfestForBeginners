#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string s = to_string(n);
    int slen = s.length();

    bool flag = 1;

    for (int i = 0; i < slen; i++)
    {
        if (s[i] != s[slen - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}