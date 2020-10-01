//	code by Himanshu Pandey

#include<bits/stdc++.h>
#define int long long
#define loop(I,N) for(int i=I;i<N;i++)

void solve(){
	int n,sum = 0;
	cin>>n;
	vector<int> a(n);
	loop(0,n){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum>=0){
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
}

int32_t main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
