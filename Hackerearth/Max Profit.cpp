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
using namespace std;

int main()
{
int n, ans=0;
scanf("%d", &n);
int a[n];
for (int i=0; i<n; i++)
{
scanf("%d", &a[i]);
for (int j=0; j<i; j++)
if (a[i]-a[j]>ans)
ans=a[i]-a[j];
}
printf("%d\n", ans);
return 0;
}
