#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int flag = 0;
    int count = 10;

    int i = 1;
    while (i <= n)
    {
        if (i % 2 == 1)
        {
            cout << count << " ";
            count = count + 10;
        }
        else
        {
            cout << i << " ";
        }
        i++;
    }
}