#include <bits/stdc++.h>
#define MAX 10000001
#define moduloN % 1000000007
using namespace std;

unsigned long long n;
unsigned long long toD[MAX];
unsigned long long toAny[MAX];

unsigned long long tetrahedron(unsigned long long x)
{
    toD[0] = 1;
    toAny[0] = 0;
    for (unsigned long long i = 1; i <= x; i++)
    {
        toD[i] = (toAny[i - 1] * 3) moduloN;
        toAny[i] = ((toAny[i - 1] * 2) + toD[i - 1]) moduloN;
    }
    return toD[x];
}

int main(void)
{
    cin >> n;
    cout << tetrahedron(n);
}