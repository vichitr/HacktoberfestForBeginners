#include<bits/stdc++.h>
using namespace std;

int maxsumsubarray(int a[],int n,int k,int x){
    int sum=0,msum=0;
    if(n<k)
    return -1;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    if(sum<x)
    msum=sum;
    for(int i=k;i<n;i++){
        sum=sum + a[i] - a[i-k];
        if(sum<x)
        msum=max(msum,sum);
    }
    return msum;
}

int main(){
    int a[]={7,5,4,6,8,9};
    int n=6;
    int k=3;
    int x=20;
    cout<<maxsumsubarray(a,n,k,x);
}