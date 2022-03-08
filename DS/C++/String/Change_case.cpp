#include<bits/stdc++.h>
using namespace std;

string toupper(string s,int l){
    for(int i=0;i<l;i++){
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-32;
    }
    return s;
}

string tolower(string s,int l){
    for(int i=0;i<l;i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]+32;
    }
    return s;
}
int main(){
    string s;
    getline(cin,s);
    int l=s.length();
    cout<<toupper(s,l)<<endl;
    cout<<tolower(s,l);
}