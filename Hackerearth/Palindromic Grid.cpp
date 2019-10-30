//Code by Abhishek Tiwari
//Hackerearth : https://www.hackerearth.com/@become
//Github : https://github.com/becomeahacker

#include<bits/stdc++.h>
typedef long long int lli;
typedef long long ll;
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define fi(n) for(int i=0;i<n;++i)
#define fj(n) for(int j=0;j<n;++j)
#define f1(n) for(int i=1;i<n;++i)
#define pii pair<int,int>
using namespace std;


int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int t; cin>>t;
while(t--){

int m,n;
cin>>n>>m;
int count[26]={0};
int single = 0,pairs=0; string ent;
fi(n){cin>>ent; fj(m) ++count[ent[j]-'a'];}
fi(26)
{
    if(count[i]%2)
    {
        ++single;

    }
    count[i]=count[i]>>1;
    if(count[i]%2)
    {
        ++pairs;
    }
}
//cout<<"P : "<<pairs<<"s: "<<single<<flush;
bool flag=false;
if(m%2)
{
    if(n%2)
    {
        if(single==1 && pairs <=(m/2+n/2))
            flag=true;
        else
            flag=false;
    }
    else
    {
        if(single==0 && pairs <= n/2)
            flag=true;
        else
            flag=false;
    }
}
else
{
    if(n%2)
    {
        if(single==0 && pairs <= m/2)
            flag=true;
        else
            flag=false;
    }
    else
    {
        if(single==0 && pairs==0)
            flag=true;
        else
            flag=false;
    }
}
if(flag)
    cout<<"YES\n"<<flush;
else
    cout<<"NO\n"<<flush;


}

return 0;
}
