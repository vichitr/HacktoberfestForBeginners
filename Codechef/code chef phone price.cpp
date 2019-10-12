#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		long int n,i,s=1,min,j,pos,ar[1000];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		min=ar[0];
		for(i=0;i<n;i++)
		{
			if(min>ar[i]&&i<5)
			{
				min=ar[i];
				pos=i;
				s++;
			}
			else if(i>=5)
			{
				for(j=i-5;j<i;i++)
				{
					if(ar[i]>ar[j])
					{
						s++;
					}
				}
			
			}
		}
		cout<<s<<endl;
	}
}
