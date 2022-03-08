#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int n;
    if(b>a)
    swap(a,b);
    while(b!=0){
        n=a%b;
        a=b;
        b=n;
    }
    cout<<a;
}