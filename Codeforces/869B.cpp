//URL - https://codeforces.com/problemset/problem/869/B


#include<bits/stdc++.h>

using namespace std;

int main() {

    long long int a, b;
    cin >> a >> b;

    long long int lastDigit, res;

    long long int check = b - a;
    
    if(check != 0 && b % 10 == 0) {
        res = 0;
    }
    else if(check >= 2) {
        res = ( ( ( a + 1 ) % 10 ) * ( ( a + 2 ) % 10 ) ) % 10; 
        //cout << "Iteration " << a + 2 << " : " << res << endl;

        for(long long int i = a + 3; res != 0 && i <= b; i += 1) {
            res = ( res * ( i % 10 ) ) % 10;
            //cout << "Iteration " << i << " : " << res << endl;
        }
    }
    else if(check == 1) {
        res = b%10;
    }
    else {
        res = 1;
    }

    cout << res << endl;

    return 0;
}