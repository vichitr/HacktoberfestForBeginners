#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int n,int s){
    int l=0;
    int r=n-1;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==s)
            return mid;
        else if(a[mid]>s)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    cin>>s;
    int result=binary_search(a,n,s);
    cout<<result;
}