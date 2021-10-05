#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < b + 1; i++)
    {
        if ((a - i) % b == 0)
        {
            cout << a - i << endl;
            break;
        }
    }

    return 0;
}