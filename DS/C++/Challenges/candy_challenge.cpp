#include<bits/stdc++.h>
using namespace std;

int main(){
    int candy;
    cin>>candy;    
    int wrapper=candy;
    while(wrapper>=3){
        candy+=wrapper/3;
        wrapper= wrapper/3 + wrapper%3;
    }
    cout<<candy;
}