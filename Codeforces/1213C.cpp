#include <bits/stdc++.h>

using namespace std;

int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        if((m%2==0 && m%5==0) || m>n)
        {
            cout<<0<<endl;
        }
        else if(m%2==0)
        {
            long long a[5],k=0,i=m,sum=0,terms=n/m,ans=0;
            while(k!=5)
            {
                a[k]=i%10;
                sum+=a[k];
                k++;
                i+=m;
            }
            ans=sum*(terms/5);
            for(long long j=0;j< terms%5;j++)
            {
                ans+=a[j];
            }
            cout<<ans<<endl;

        }
        else if(m%5==0)
        {
            long long a[2],k=0,i=m,sum=0,terms=n/m,ans=0;
            while(k!=2)
            {
                a[k]=i%10;
                sum+=a[k];
                k++;
                i+=m;
            }
            ans=sum*(terms/2);
            for(long long j=0;j< terms%2;j++)
            {
                ans+=a[j];
            }
            cout<<ans<<endl;
        }
        else
        {
            long long a[10],k=0,i=m,sum=0,terms=n/m,ans=0;
            while(k!=10)
            {
                a[k]=i%10;
                sum+=a[k];
                k++;
                i+=m;
            }
            ans=sum*(terms/10);
            for(long long j=0;j< terms%10;j++)
            {
                ans+=a[j];
            }
            cout<<ans<<endl;
        }

    }



    return 0;
}
