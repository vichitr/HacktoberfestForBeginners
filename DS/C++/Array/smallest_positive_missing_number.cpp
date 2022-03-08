#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=a[0],i;
    for( i=1;i<n;i++){
        m=max(a[i],m);
    }
    bool idx[m+1];
    for( i=0;i<m+1;i++){
        idx[i]=false;
    }
    for( i=0;i<n;i++){
        if(a[i]>0){
            idx[a[i]]=true;
        }
    }
    int missing=-1;
    for( i=1;i<m+1;i++){
        if(idx[i]==false){
            missing=i;
            break;
        }
    }
    cout<<missing;

}