#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,temp;
    stack<string> st;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            st.push(temp);
            temp="";
        }
        else
        temp=temp+s[i];
    }
    st.push(temp);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}