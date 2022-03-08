#include<bits/stdc++.h>
using namespace std;

string replace_pi(string s){
    if(s.length()==0)
    return "";

    if(s[0]=='p' && s[1]=='i')
        return "3.14"+replace_pi(s.substr(2));
    return s[0]+replace_pi(s.substr(1));    
    
}

int main(){
    string s;
    getline(cin,s);
    cout<<replace_pi(s);
}