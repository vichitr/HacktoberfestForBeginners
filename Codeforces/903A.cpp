//903A - Hungry Student Problem
//Author : wgarcia1309
#include<bits/stdc++.h>
using namespace  std;
int main(){
    int n;
    bool r[110];
    for(int i=0;i<=109;i++)r[i]=false;
    for(int i=3;i<=100;i+=3){
            r[i]=true;
        for(int j=7;j<=100;j+=7){
                r[j]=true;
                if(i+j<=100)r[i+j]=true;
        }
    }
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        if(r[t])cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}