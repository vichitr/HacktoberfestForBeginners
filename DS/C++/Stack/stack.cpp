#include<iostream>
using namespace std;
#define n 100

class stack{
    int top;
    int *a;
    public:
    stack(){
        top=-1;
        a=new int[n];
    }
    void push(int el){
        if(top==(n-1)){
            cout<<"stack overload";
            return;
        }
        top++;
        a[top]=el;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty";
            return;
        }
        cout<<a[top]<<endl;
        top--;
    }
    int Top(){
        return top;
    }
    bool empty(){
        if(top==-1){
            return 1;
        }
        else
            return 0;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty();
}