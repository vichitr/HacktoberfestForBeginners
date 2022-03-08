#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> st1;
    stack<int> st2;
    public:
    
    void push(int n){
        
        st1.push(n);
    }
    void pop(){
        if(st1.empty()&& st2.empty()){
            cout<<"queue is empty";
            return;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        st2.pop();
        
    }
    int peek(){
        if(st1.empty()&& st2.empty()){
            cout<<"queue is empty";
            return -1;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
        
    }
    bool empty(){
        if(st1.empty() && st2.empty())
        return 1;
        return 0;
    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout<<q.peek()<<endl;
     q.pop();
    cout<<q.peek()<<endl;
     q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
}