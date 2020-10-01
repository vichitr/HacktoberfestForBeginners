//Author: Vishal Kharade
//Hacktoberfest Submission

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    ll n;cin>>n;
    ll sum = 0;
    for(ll i = 0; i<n; i++) {
        ll temp; cin>>temp;
        sum+=temp;
    }
    if(sum >= 0) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin>>t;
    while(t--) {
        solve();
    }
}