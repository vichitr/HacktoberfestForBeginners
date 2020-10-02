#include<iostream>
using namespace std;
int main()
{

    int t,i,total,check;
    int n,q;
    cin>>t;

    while(t--)

    {

        check=0;

        cin>>n>>q;

        int a[n];

        for(i=0;i<n;i++)
            cin>>a[i];

        total=a[0];
               //7 3 6 5

        for(i=1;i<=n;i++)
        {
    
            total-=q;

            if(total<0)
            {
            check=1;
            break;
            }
            total+=a[i];
        }

        if(check==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO "<<i<<endl;
    }
}