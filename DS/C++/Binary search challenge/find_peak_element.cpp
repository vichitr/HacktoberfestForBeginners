#include<bits/stdc++.h>
using namespace std;

int find_peak(int a[],int start,int end,int n){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if((mid==n-1 || a[mid]>=a[mid+1] ) && (mid==0 || a[mid]>=a[mid-1]))
        return mid;
    else if(mid>0 && a[mid-1]>a[mid])
        return find_peak(a,0,mid-1,n);
    else
        return find_peak(a,mid+1,end,n);    
}

int main(){
    int a[]={0,6,8,5,7,9};
    int n=6;
    cout<<find_peak(a,0,n,n);
}