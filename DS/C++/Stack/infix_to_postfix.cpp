#include<bits/stdc++.h>
using namespace std;

int preced(char ch){
    if(ch=='^')
    return 3;
    else if(ch=='/'|| ch=='*')
    return 2;
    else if(ch=='-'||ch=='+')
    return 1;
    else
    return -1;
}

string infix_postfix(string s){
    stack<char> st;
    string p="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9')
        p+=s[i];
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                p+=st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else{
            while(!st.empty() && preced(st.top())>=preced(s[i])){
                p+=st.top();
                st.pop();
            }
            st.push(s[i]);            
        }
    }
    while(!st.empty()){
        p+=st.top();
        st.pop();
    }
    return p;
}

int main(){
    string s;
    cin>>s;
    cout<<infix_postfix(s);
}