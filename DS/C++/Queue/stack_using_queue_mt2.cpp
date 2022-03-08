#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
    int N;
    Stack(){
        N=0;
    }
    void push(int n){
        q1.push(n);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }  
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        N++;
    }
    void pop(){
        if(q2.empty()){
            cout<<"stack is empty";
            return;
        }
        q2.pop();
        N--;
    }
    int top(){
        if(q2.empty()){
            cout<<"stack is empty";
            return -1;
        }
        return q2.front();
    }
    bool empty(){
        if(q2.empty())
        return 1;
        return 0;
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
}