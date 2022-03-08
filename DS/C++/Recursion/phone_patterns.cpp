#include<bits/stdc++.h>
using namespace std;

string pattern[]={" ","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    int c=s[0]-'0';
    string ros=s.substr(1);
    for(int i=0;i<pattern[c].length();i++){
        keypad(ros,ans+pattern[c][i]);
    }
}

int main(){
    string s;
    cin>>s;
    keypad(s,"");
}