//hackerearth problem picked from noveasy19
#include<bits/stdc++.h>
using naemespace std;
#define ll long long int
int main()
{
    int n,q,i;
    cin>>n>>q;
    ll a[n],p,g=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        g=__gcd(a[i],g);
    }
    while(q--)
    {
     cin>>p;
    if(__gcd(g,p)==g)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
 
}
