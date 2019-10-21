// code by yctseng1227
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define PB push_back
typedef long long ll;
using namespace std;
 
#define MAXN 200005
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int main()
{_
    ll n, g, MAX=0; cin >> n;
    vector<ll> vv(n), v;
    for(int i=0; i<n; i++){
        cin >> vv[i];
        MAX = max(MAX, vv[i]);
    }
    for(int i=0; i<n; i++){
        int tmp = abs(MAX-vv[i]);
        if(tmp) v.PB(tmp);
    }
 
    g = v[0];
    for(int i=1; i<v.size(); i++){
        g = gcd(g, v[i]);
    }
    ll cnt = 0;
    for(int i=0; i<v.size(); i++){
        cnt += v[i] / g;
    }
    if(n == 2){
        cout << "1" << endl << abs(vv[0]-vv[1]) << endl;
    }else{
        cout << cnt << endl << g << endl;
    }
 
    return 0;
}
