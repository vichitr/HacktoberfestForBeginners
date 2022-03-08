#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mlen=2,l=1;
    int diff=0;
    for(int i=0;i<n;i++){
        if((a[i]-a[i-1])!=diff){
            diff=a[i]-a[i-1];
            l=1;
        }
        l++;
        mlen=max(mlen,l);
    }
    cout<<mlen;
}