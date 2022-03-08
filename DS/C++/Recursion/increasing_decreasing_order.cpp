#include<bits/stdc++.h>
using namespace std;

void increasing(int n){
    if(n==0)
    return;
    cout<<n<<" ";
    increasing(n-1);
}

void decreasing(int n){
    if(n==0)
    return;
    decreasing(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cin>>n;
    decreasing(n);
    increasing(n);
}