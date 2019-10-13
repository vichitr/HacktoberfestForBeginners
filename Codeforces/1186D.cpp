#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,l;
    double k,m=0.00000;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(m>0)
        {
            m=(m-(k-floor(k)));
            l=floor(k);
            cout<<l<<"\n";
        }
        else
        {
            m=(m+(ceil(k)-k));
            l=ceil(k);
            cout<<l<<"\n";
        }
    }
    return 0;
}
