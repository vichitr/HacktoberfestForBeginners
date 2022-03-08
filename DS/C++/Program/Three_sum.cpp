#include<bits/stdc++.h>
using namespace std;

bool three_sum(int a[],int n,int k){
    sort(a,a+n);
    int start,end;
    bool flag=false;
    for(int i=0;i<n-2;i++){
        int sum=k-a[i];
        start=i+1,end=n-1;
        while(start<end){
            if(a[start]+a[end]==sum){
                flag=1;
                break;
            }
            else if(a[start]+a[end]<sum)
            start++;
            else
                end--;            
        }        
    }
    return flag;
}

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    cout<<three_sum(a,n,k);
}