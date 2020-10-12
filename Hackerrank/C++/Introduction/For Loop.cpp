#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

int a, b;
string represent[10] = {"zero", "one", "two", "three", "four",
                        "five","six", "seven", "eight","nine"};
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(i > 9) {
            if(i % 2 == 0)
                cout << "even\n";
            else cout << "odd\n";
        }
        else {
            cout << represent[i]<<endl;
        }
    }
    return 0;
}
