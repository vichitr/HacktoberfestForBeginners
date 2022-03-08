#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=a[0];
    for(i=0;i<n;i++){
        mx=max(mx,a[i]);
    }
    int idx[mx+1];
    for(i=0;i<mx+1;i++){
        idx[i]=-1;
    }
    
    int sum=0,msum=INT_MAX,pos=-1;
    for(i=0;i<n;i++){
        if(a[i]>0){
            if(idx[a[i]]==-1){
                idx[a[i]]=i;                
            }                
            else{
                    sum=idx[a[i]]+i;                    
                    if(sum<msum){
                        msum=sum;
                        pos=idx[a[i]];
                    }
                    
                }
        }
    }
    
    cout<<pos;
}