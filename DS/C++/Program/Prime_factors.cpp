#include<bits/stdc++.h>
using namespace std;

void prime_factors(int n){
    int a[n+1];
    for(int i=0;i<=n;i++){
        a[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            if(a[j]==j)
                a[j]=i;
        }
    }

    while(n!=1){
        cout<<a[n]<<" ";
        n=n/a[n];
    }
}

int main(){
    int n;
    cin>>n;
    prime_factors(n);
}