#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,ar[1000],sum=0,t,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<t;i++)
    {
        j=i;
        while(ar[j]<ar[j+1]&&j>=0)
        {
            n=ar[j];
            ar[j]=ar[j+1];
            ar[j+1]=n;
            j--;
        }
    }
    for(i=0;i<t;i++)
    {
        sum=sum+pow(2,i)*ar[i];
        
    	cout<<sum<<endl;
    }
    cout<<sum;
}
