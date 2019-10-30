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
#define vi vector<int>
#define tc int t; cin>>t; while(t--)
using namespace std;


int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
tc{
string s;
getline(cin,s);
int a[26]={0};
fi(s.length())
{
    if(s[i]!=' ')
    a[s[i]-'a']++;
}
getline(cin,s);
fi(s.length())
{
    if(s[i]!=' ')
    a[s[i]-'a']--;
}
bool fir=false,sec=false;
fi(26)
{
    if(a[i]>0)
        fir=true;
    if(a[i]<0)
    sec=true;
}
if(fir && sec)
    cout<<"You draw some."<<"\n";
else {
    if(fir)
        cout<<"You win some.\n";
    else
        cout<<"You lose some.\n";
}
}


return 0;
}
