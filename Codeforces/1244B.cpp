#include <bits/stdc++.h>
using namespace std;
using LL =long long;
int a[1004],ones,zeros;

int main() {
    LL t,k,count=0;
    cin>>t;
    string str;
    while(t--)
    {
        cin>>k;
        cin>>str;
        int y=0,z1=0,z2=0;
        while(!(str[y++]-'0'))z1++;
        y=k-1;
        while(!(str[y--]-'0'))z2++;

        if(str[0]=='1'|| str[k-1]=='1')
                cout<<2*k<<endl;
        else if(z1==k)
                cout<<k<<endl;
        else
        {
            int min1=min(z1,z2);
            cout<<2*(k-min1)<<endl;
        }
        
    }
}
