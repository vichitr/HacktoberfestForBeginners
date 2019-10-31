#include <iostream>
using namespace std;

int main(){
    
    long long k, b, n, t;
    cin >> k >> b >> n >> t;
    for(long long s = k + b; s <= t && n > 0; s = k * s + b, --n);
    cout << n;
    
    return 0;
}
