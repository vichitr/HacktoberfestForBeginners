#include<bits/stdc++.h>
using namespace std;

void add_buttom(stack<int> &st,int n){
    if(st.empty()){
        st.push(n);
        return;
    }
    int topel=st.top();
    st.pop();
    add_buttom(st,n);    
    st.push(topel);
}

void reverse_stack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int n=st.top();
    st.pop();
    reverse_stack(st);
    add_buttom(st,n);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse_stack(st);
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}