#include <bits/stdc++.h>
using namespace std;
using LL =long long;
LL x,y,z;

int main() {
    LL n,sum1=0,sum2=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    
    for(int i=0;i<n/2;i++)sum1+=a[i];
    for(int i=n/2;i<n;i++)sum2+=a[i];
  
    LL sum=(sum1*sum1)+(sum2*sum2);
    cout<<sum;
}
        
    
