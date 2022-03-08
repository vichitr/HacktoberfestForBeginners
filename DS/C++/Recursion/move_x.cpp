#include<bits/stdc++.h>
using namespace std;

string movex(string s){
    if(s.length()==0)
    return "";

    char ch=s[0];
    if(ch=='x')
    return movex(s.substr(1))+ch;
    else
    return ch+movex(s.substr(1));
}

int main(){
    string s;
    getline(cin,s);
    cout<<movex(s);
}