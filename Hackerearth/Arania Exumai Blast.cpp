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
string s;
int i,count=0;
getline(cin,s);
for(i=0;i<s.length();i++)
{
if(s[i]==s[i+1])
{
count++;
}
}
printf("%d",count);

return 0;
}
