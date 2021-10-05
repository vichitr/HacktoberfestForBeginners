#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 3;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << endl;
    }

    int MIN = INT_MAX;
    int MAX = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        MIN = min(MIN, arr[i]);
        MAX = max(MAX, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != MIN && arr[i] != MAX)
        {
            cout << arr[i] << endl;
            break;
        }
    }

    return 0;
}