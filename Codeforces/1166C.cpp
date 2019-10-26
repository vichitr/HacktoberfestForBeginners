// code by yctseng1227
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
 
#define MAXN 200005

int main()
{_
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]<0) v[i]*=-1;
    }
    sort(ALL(v));
 
    ll ans = 0, k=1;
    for(int i=0; i<n-1; i++){
        //int k = n-1;
        while(v[k] <= v[i]*2 && k<n) k++;
        ans += (k-i-1);
    }
    cout << ans << endl;
 
    return 0;
}