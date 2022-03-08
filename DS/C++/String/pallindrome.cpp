#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
    int l=s.length();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i])
            return false;
    }
    return true;
}

int main(){
    string s;
    getline(cin,s);
    cout<<ispalindrome(s);
}