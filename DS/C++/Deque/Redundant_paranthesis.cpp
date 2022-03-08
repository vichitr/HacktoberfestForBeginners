#include<bits/stdc++.h>
using namespace std;

bool redundant_paranthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        st.push(s[i]);
        else if(s[i]==')'){
            if(st.empty() || st.top()=='(')
            return false;
            while(!st.empty() && (st.top()=='+'||st.top()=='/'||st.top()=='-'||st.top()=='*')){
                st.pop();
            }
            if(!st.empty())
            st.pop();
            else
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<redundant_paranthesis(s);
}