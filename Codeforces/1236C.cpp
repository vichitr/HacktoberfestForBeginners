#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n,k=1,m=0;
    cin>>n;
    int a[n][n];
        for(int i=0;i<n;i++){
            m=m^1;
            for(int j=0;j<n;j++)
            {
                if(m)
                    a[j][i]=k;
                else 
                    a[n-j-1][i]=k;
                k++;
            }
    
        }
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
                
            cout<<endl;
            }
}
        
    
