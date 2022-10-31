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
    int n;
    cin>>n;
    vector<int> d(n, 0), a(n, 0);
    for(int i=0; i<n; i++) {
        cin>>d[i];
    }

    a[0] = d[0];
    for(int i=1; i<n; i++) {
        int one = a[i-1] + d[i];
        int two = a[i-1] - d[i];

        if(one != two && one >=0 && two >= 0) {
            // cout<<a[i-1]<<" "<<one<<" "<<two<<"\n";
            cout<<"-1\n";
            return;
        }

        a[i] = max(one, two);
    }

    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

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