#include<bits/stdc++.h>
using namespace std;

int friend_pairing(int n){
    if(n==0 ||n==1 || n==2)
    return n;
    return friend_pairing(n-1) + friend_pairing(n-2)*(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<friend_pairing(n);
}