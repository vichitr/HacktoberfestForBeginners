#include<bits/stdc++.h>
using namespace std;

void substring(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }    

    string ros=s.substr(1);
    substring(ros,ans);
    substring(ros,ans+s[0]);
}

int main(){
    string s;
    getline(cin,s);
    substring(s,"");
}