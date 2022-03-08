#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    if(n<=1)
    return 1;
    int ans=0;
    for(int i=0;i<=n-1;i++){
        ans+=catalan(i)*catalan(n-i-1);
    }
    return ans;
}

int main(){
    for(int i=0;i<=8;i++){
        cout<<catalan(i)<<" ";
    }
}