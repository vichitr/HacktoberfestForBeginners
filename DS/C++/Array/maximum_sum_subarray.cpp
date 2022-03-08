#include<bits/stdc++.h>
using namespace std;

int bruteforce_method(int a[],int n){
    int sum=0,mxsum=INT_MIN;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum=sum+a[j];
            mxsum=max(sum,mxsum);
        }
    }
    return mxsum;
}

int kadane(int a[],int n){
    int mxsum=INT_MIN,currentsum=0;
    for(int i=0;i<n;i++){
        currentsum+=a[i];
        if(currentsum<0)
            currentsum=0;
        mxsum=max(currentsum,mxsum);    
    }
    return mxsum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mxsum=kadane(a,n);
    cout<<mxsum;
}