#include<bits/stdc++.h>
using namespace std;

int minsubarraysize(int a[],int n,int x){
    int sum=0;
    int s=0,e=0,size=0,msize=n+1;
    while(s<=e && e<n){
        sum=sum+a[e];        
        while(sum>x && s<n){
            size=e-s+1;
            msize=min(msize,size);
            sum=sum-a[s];
            s++;
        }
        e++;
    }
    return msize;
}

int main(){
    int a[]={1,4,45,6,10,29};
    int n=6;
    int x=51;
    int msize=minsubarraysize(a,n,x);
    if(msize==n+1)
    cout<<"No such subarray exist";
    else
    cout<<msize;
}