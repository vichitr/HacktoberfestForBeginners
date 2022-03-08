#include<bits/stdc++.h>
using namespace std;

int max_consecutive_one(int a[],int n,int k){
    int c=0,i=0,maxlen=0;
    for(int j=0;j<n;j++){
        if(a[j]==0)
        c++;        
        while(c>k){
            if(a[i]==0)
            c--;
            i++;
        }
        maxlen=max(maxlen,j-i+1);
    }
    return maxlen;
}

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    cout<<max_consecutive_one(a,n,k);
}