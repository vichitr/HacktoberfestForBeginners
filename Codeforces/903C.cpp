//903C - Boxes Packing
//Author : wgarcia1309
#include<bits/stdc++.h>
using namespace  std;
int main(){
    int n,c[5000],r[5000],ind=0;
    cin>>n;
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)cin>>r[i];
    sort(r,r+n);
    if(n>1){
        c[0]=r[n-1];
        ind++;
        bool x=true;
        for(int i=n-2;i>=0;i--){
            int m=-1;
            for(int j=0;j<ind;j++){
                if(r[i]<c[j]){
                    m=j;
                    break;
                }
            }
            if(m==-1 || r[i]>=c[m]){
                c[ind]=r[i];
                ind++;
            }else{
                c[m]=r[i];
            }
        }
        cout<<ind<<"\n";
    }else{
        cout<<"1\n";
    }
    return 0;
}
