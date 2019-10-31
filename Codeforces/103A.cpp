#include <cstdio>
#include <iostream>
using namespace std;

int main() {

    long long n;
    cin >> n;
    long long total(0);
    for(long p = 0; p < n; p++){
        long long m;
        cin >> m;
        total += (m - 1) * (p + 1) + 1;
    }

    cout << total << endl;

    return 0;
}
