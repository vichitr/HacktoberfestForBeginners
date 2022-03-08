#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;    
    int ans[n-k];
    int mx;
    for(int i=0;i<n-k;i++){
        mx=a[i];
        for(int j=0;j<k;j++){
            mx=max(a[j+i],mx);
        }
        ans[i]=mx;
    }
    for(int i=0;i<n-k;i++)
    cout<<ans[i]<<" ";
}