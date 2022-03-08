#include<bits/stdc++.h>
using namespace std;

void permuation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    for(int i=0;i<s.length();i++){
        string ros=s.substr(0,i)+s.substr(i+1);        
        permuation(ros,ans+s[i]);
    }
}

int main(){
    string s;
    cin>>s;
    permuation(s,"");
}