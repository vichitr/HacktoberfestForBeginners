#include<bits/stdc++.h>
using namespace std;

void substring(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    int ch=s[0];
    string ros=s.substr(1);
    substring(ros,ans);
    substring(ros,ans+s[0]);
    substring(ros,ans+to_string(ch));
}

int main(){
    string s;
    getline(cin,s);
    substring(s,"");
}