// CPP program to find median
#include <bits/stdc++.h>
using namespace std;

double findMedian(int a[], int n)
{
    // First we sort the array
    sort(a, a + n);

    if (n % 2 != 0)
        return (double)a[n / 2];

    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 5;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << findMedian(a, n) << endl;
    }
    return 0;
}
