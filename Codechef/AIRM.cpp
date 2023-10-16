#include <bits/stdc++.h>
using namespace std;

int countMax(int arr[], int size) 
{
    unordered_map<int, int> count;
    int mx = 0;
    for (int i = 0; i < size; i++) 
    {
        count[arr[i]]++;
        mx = max(mx, count[arr[i]]);
    }

    return mx;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;
        int a[2 * n];

        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        cout << countMax(a, 2 * n) << endl;
    }

    return 0;
}
