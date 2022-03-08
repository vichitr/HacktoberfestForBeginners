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

string infix_to_prefix(string s){
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9')
        ans+=s[i];
        else if(s[i]==')')
        st.push(s[i]);
        else if(s[i]=='(')
        {
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();                
        }
        else{
            while(!st.empty() && preced(st.top())>preced(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<infix_to_prefix(s);
}