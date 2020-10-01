//	code by Himanshu Pandey

#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define loop(I,N) for(int i=I;i<N;i++)
#define sortvec(V) sort(V.begin(),V.end())
#define vec vector<int>
#define endl "\n"
using namespace std;
#define PI 3.14159265359
int fast_power(int base, int power) {int result = 1; while (power > 0) { if (power & 1) {            result = (result * base) % MOD;        }        base = (base * base) % MOD;power = power >> 1;}    return result % MOD;}
bool isPrime(int x) {    for (int i = 2; i <= sqrt(x); i++) {        if (x % i == 0)            return false;    }    if (x == 1)        return false;    return true;}
int inv(int a, int m){    int m0 = m, t, q;    int x0 = 0, x1 = 1;    if (m == 1)       return 0;  	while (a > 1) {        q = a / m;  		t = m;  		m = a % m, a = t;  		t = x0;		x0 = x1 - q * x0;  		x1 = t;    }    if (x1 < 0)       x1 += m0;    return x1;}
int CRT(int num[], int rem[], int k){    int prod = 1;    for (int i = 0; i < k; i++)        prod *= num[i];	int result = 0;	for (int i = 0; i < k; i++){        int pp = prod / num[i];        result += rem[i] * inv(pp, num[i]) * pp;    }    return result % prod;}
int binsearch(int a[], int f, int r, int x) {    while (f <= r) {        int mid = (f + r) / 2;        if (a[mid] == x)            return mid;        else if (a[mid] > x) {            r = mid - 1;}        else {            f = mid + 1;}    }    return -1;}
void SieveOfEratosthenes(int n){    bool prime[n+1];    memset(prime, true, sizeof(prime));    for (int p=2; p*p<=n; p++)    {        if (prime[p] == true)        {            for (int i=p*p; i<=n; i += p)                prime[i] = false;        }    }	for (int p=2; p<=n; p++)       if (prime[p])          cout << p << " ";}

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
