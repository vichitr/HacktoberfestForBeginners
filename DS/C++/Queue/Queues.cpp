#include<bits/stdc++.h>
using namespace std;
#define n 100

class Queue{
    int front,back;
    int *a;
    public:
    Queue(){
        a=new int[n];
        front=-1;
        back=-1;
    }
    void push(int el){
        if(back==(n-1)){
        cout<<"queue overload";
        return;
        }
        back++;
        a[back]=el;
        if(front==-1)
        front++;
    }
    void pop(){
        if(front==-1 ||front>back){
            cout<<"queue empty";
            return;
        }
        front++;
    }
    int peek(){
        if(front>back || front==-1){
        cout<<"queue is empty";
        return;
        }
        return a[front];
    }
    bool empty(){
        if(front>back || front==-1)
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