#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){            
            if(!st.empty() && st.top()=='(')
            st.pop();
            else{
                cout<<-1;
                return 0;
            }
        }
        else if(s[i]=='}'){            
            if(!st.empty() && st.top()=='{')
            st.pop();
            else{
                cout<<-1;
                return 0;
            }
        }
        else if(s[i]==']'){            
            if(!st.empty() && st.top()=='[')
            st.pop();
            else{
                cout<<-1;
                return 0;
            }
        }
    }

    if(st.empty())
    cout<<"true";
    else
    cout<<-1;
}