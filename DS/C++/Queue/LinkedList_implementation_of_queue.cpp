#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int n){
        data=n;
        next=NULL;
    }
};

class Queue{
    
    node* front;
    node* back;
    public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void push(int n){
        node* el=new node(n);
        if(back==NULL){
            back=el;
            front=el;
        }
        else{
            back->next=el;
            back=el;
        }
    }

    void pop(){
        if(front==NULL){
            cout<<"queue is empty";
        }
        node* temp=front;
        front=front->next;
        delete temp;
    }
    int peek(){
        if(front==NULL)
        cout<<"queue is empty";
        return (front->data);
    }
    bool empty(){
        if(front==NULL)
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
    cout<<q.empty()<<endl;
}