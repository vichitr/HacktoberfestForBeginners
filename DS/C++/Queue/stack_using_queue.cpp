#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
    public:
    Stack(){
        N=-1;
    }
    void push(int n){
        q1.push(n);
        N++;
    }
    void pop(){
        if(q1.empty())
        cout<<"stack is empty";
        
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
            
        }
        q1.pop();
        N--;
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    int top(){
        if(q1.empty())
        cout<<"stack is empty";
        
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
            
        }
        int ans=q1.front();
        q2.push(ans);
        q1.pop();
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return ans;
    }
    bool empty(){
        if(q1.empty())
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