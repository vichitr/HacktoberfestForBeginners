#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long b,g,n,bmax,gmax,gmin,bmin;
    
    cin>>b>>g>>n;
    
    bmax=min(n,b);
    gmax=min(n,g);
    
    gmin=min(n-bmax , gmax);
    bmin=min(n-gmax , bmax);
    
    cout<<min(bmax-bmin+1,gmax-gmin+1);
    
    return 0;
}
