#include<bits/stdc++.h>
using namespace std;

int isfisible(int a[],int mid,int n,int m){
    int c=1,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid)
        return 0;
        sum+=a[i];
        if(sum>mid){
            sum=a[i];
            c++;
        }
    }
    if(c<=m)
    return 1;
    return 0;
}

int page_allocation(int a[],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

    int s=0,e=sum,ans=INT_MAX;
    while(s<e){
        int mid=(s+e)/2;
        if(isfisible(a,mid,n,m)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}

int main(){
    int a[]={12,34,67,90};
    int n=4;
    int m=2;
    sort(a,a+n);
    cout<<page_allocation(a,n,m);
}