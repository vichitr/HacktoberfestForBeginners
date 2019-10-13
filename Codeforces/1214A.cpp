#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,d,e;
    cin>>n>>d>>e;
    long long x1,x2,y1,y2,ans1=INT_MAX,ans2=INT_MAX;
    x1=n/(5*e);
    while(x1!=-1)
    {
        y1=(n-(5*e*x1))/d;
        ans1=n-(5*e*x1)-(y1*d);
        ans2=min(ans1,ans2);
        if(ans2==0)
        {
            cout<<ans2;
            return 0;
        }
        x1--;
    }
    ans1=ans2;

    y2=n/d;
    while(y2!=-1)
    {
        x2=(n-(y2*d))/(5*e);
        ans2=n-(5*e*x2)-(y2*d);
        ans1=min(ans1,ans2);
        if(ans1==0)
        {
            cout<<ans1;
            return 0;
        }
        y2--;
    }

    cout<<ans1;

    return 0;
}
