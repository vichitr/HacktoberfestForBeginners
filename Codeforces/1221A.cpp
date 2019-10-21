#include <bits/stdc++.h>
using namespace std;
using LL =long long;
 
int main() {
    LL t,n,a,b;
    cin>>t;
    while(t--){
            b=0;
            cin>>n;
            unordered_map<int,int> um;
            for(int i=0;i<n;i++)
            {  
                cin>>a;
                if(a<=2048)
                um[a]++;
            }
            for(int i=0;i<12;i++)
            {
                if(um[1<<i]>=2)um[1<<(i+1)]+=um[1<<i]/2;
            }
            if(um[2048])cout<<"YES"<<endl;
            else cout<<"NO"<<endl; 
        }
}
