#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define lli long long int
#define ld long double
#define pb push_back

ll mod = 1e9 + 7;

ll gcd(ll firstNumber, ll secondNumber) {
    if (secondNumber == 0) return firstNumber;
    else return gcd(secondNumber, firstNumber % secondNumber);
}


// CODE START

void solveITcaptain() {
    int n, m;
    cin >> n >> m;

    if (n == 1 || m == 1) {
        cout << n << " " << m << "\n";
    }
    else if (n <= 3 && m <= 3) {
        cout<<ceil(n/2.0) << " "<< ceil(m/2.0)<<"\n";
    }
    else {
        cout << "1 1\n";
    }
}

// CODE END


int main() {
    system("cls");
    ios_base::sync_with_stdio(false);    cin.tie(nullptr);     cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solveITcaptain();
    }
    return 0;
}