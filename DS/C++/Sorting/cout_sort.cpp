#include<bits/stdc++.h>
using namespace std;

void count_sort(int a[],int n){
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);        
    }
    int s[mx+1]={0};
    
    for(int i=0;i<n;i++){
        s[a[i]]++;
    }
    for(int i=1;i<=mx;i++){
        s[i]=s[i]+s[i-1];
    }
    int temp[n];
    for(int i=n-1;i>=0;i--){
        temp[--s[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    count_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}