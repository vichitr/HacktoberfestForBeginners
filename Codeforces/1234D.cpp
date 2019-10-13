#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> pll;
const ll M=1e9+7;
ll inf=1e18;
ll tree[1000000];
ll a[N];
ll vis[26];
void build(ll node,ll start,ll end,ll a[])
{
    if(start==end) {
        tree[node] = a[start];
    }
    else
    {
        ll mid=(start+end)/2;
        build(2*node,start,mid,a);
        build(2*node+1,mid+1,end,a);
        tree[node] = tree[2*node]|tree[2*node+1];
    }
}
void update(ll node,ll start, ll end , ll a[],ll idx,ll val)
{
    if(start==end)
    {
        a[idx]=val;
        tree[node]=val;
    }
    else
    {
        ll mid=(start+end)/2;
        if(idx>=start && idx<=mid)
        {
            update(2*node,start,mid,a,idx,val);
        }
        else
        {
            update(2*node+1,mid+1,end,a,idx,val);
        }
        tree[node] = tree[2*node]|tree[2*node+1];
    }
}
ll query(ll node,ll start,ll end, ll l, ll r)
{
    if(l>end || r<start)
        return 0;
    else if(l<=start && r>=end)
        return tree[node];
    else
    {
        ll mid= (start+end)/2;
        ll p1,p2;
        p1=query(2*node,start,mid,l,r);
        p2=query(2*node+1,mid+1,end,l,r);
        return p1|p2;
    }
}
 
int main() {
fast;
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    ll n = s.length();
    a[0] = 0;
    for(ll i = 1;i <= n;i++) {
        a[i] = s[i-1]-'a';
        a[i] = 1LL<<a[i];
    }
    ll q;
    cin>>q;
    build(1LL,1LL,n,a);
    while(q--) {
       ll x;
       cin>>x;
       if(x == 1)
       {
           ll idx,val;
           char c;
           cin>>idx>>c;
           val = c -'a'; 
           val = 1LL<<val;  
           update(1LL,1LL,n,a,idx,val);
       }
       if(x==2)
       {
           ll l,r,ans;
           cin>>l>>r;
           ans = query(1LL,1LL,n,l,r);
           ans = __builtin_popcount(ans);
           cout<<ans<<endl;
       }
    }
    return 0;
}
