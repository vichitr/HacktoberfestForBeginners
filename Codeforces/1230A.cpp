#include <bits/stdc++.h>
using namespace std;
using LL =long long;

int main() {
    LL n,a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+b==c+d || a+c==b+d || a+d==b+c || a==b+c+d || b==a+c+d || c==a+b+d || d==a+b+c)cout<<"YES";
    else
    cout<<"NO";
    
}
