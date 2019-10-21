#include <bits/stdc++.h>
using namespace std;
using LL =long long;
 
int main() {
    LL t,c,m,x;
    cin>>t;
    while(t--){
       cin>>c>>m>>x;
       LL min1=__min(c,m);
       LL max1=(c+m+x)/3;
       min1=min(max1,min1);
       cout<<min1<<endl;
    }
}
