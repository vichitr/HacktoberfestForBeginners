#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
const ll N = 1e7+1;
ll spi[N];

void pre()
{
	ll i,j;
	for(i=1;i<N;i++)
		spi[i]=i;
	for(i=4;i<N;i+=2)
		spi[i]=2;
	for(i=3;i*i<N;i+=2)
		if(spi[i]==i)
			for(j=i*i;j<N;j=j+i)
				spi[j]=i;
}


void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	ll t,n,k,i,j,m;
	//boost();
	pre();
	scanf("%lld",&t);
	while(t--)
	{
		ll ans=1;
		scanf("%lld",&n);
		while(n>1)
		{
			m=spi[n],k=1;
			while(n%m==0)
			{
				k=k*m;
				n=n/m;
			}
			//cout<<n<<endl;
			ans*=k*k-(k*k-1)/(m+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}