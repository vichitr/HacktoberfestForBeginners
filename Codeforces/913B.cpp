#include<iostream>
using namespace std;
int main()
{
	int t,z=0,d=0,e=0;
	cin>>t;
	int a[t-1];
	int b[t]={0};
	for(int i=0;i<t-1;i++)
	{
		cin>>a[i];
		b[a[i]-1]+=1;
	}
	for(int i=0;i<t;i++)
	{
		if(b[i]>0)
		{d+=1;
			int c=0;
			for(int j=0;j<t-1;j++)
			{
			if(a[j]==i+1)
			{
				if(b[j+1]==0)
					c+=1;	
			}
			}
		if(c>=3)
		{e+=1;
		}
		else
		{
			cout<<"No"<<endl;
			z=1;
			break;
		}	
		}
	}
	if(z==0 && e==d)
		cout<<"Yes"<<endl;
		
return 0;
}	
