#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1]={0};
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i)
            if(a[j]==0)
                a[j]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==0)
        cout<<i<<" ";
    }
}