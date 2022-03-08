#include<bits/stdc++.h>
using namespace std;

int first_occr(int a[],int n,int i,int num){
    if(i==n)
    return -1;

    if(a[i]==num)
    return i;
    first_occr(a,n,i+1,num);
}

int last_occr(int a[],int n,int i,int num){
    if(i==-1)
    return -1;

    last_occr(a,n,i-1,num);
    if(a[i]==num)
        return i;    
}

int main(){
    int n,num;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>num;    
    cout<<first_occr(a,n,0,num)<<" ";
    cout<<last_occr(a,n,n-1,num);    
}