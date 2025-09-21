#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007
#define endl "\n";
#define pi 3.14159265
int add(int x, int y){return x+y;}
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	ll t;
	cin>>t;

	while(t--)
 {
	ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;

    if(a*b<10){cout<<0<<endl;}
    else if(a*b>=10 && a*b<21){cout<<c<<endl;}
    else if(a*b>=21 && a*b<42){cout<<d<<endl;}
    else{cout<<e<<endl;}
 }
	return 0;	
}

