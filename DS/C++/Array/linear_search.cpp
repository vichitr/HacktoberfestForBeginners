#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[],int n,int s){
    for(int i=0;i<n;i++){
        if(s==a[i])
            return i;
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
    int found=linear_search(a,n,s);
    cout<<found;
    
}