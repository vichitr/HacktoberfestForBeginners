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

void insertion(node* &head,int n){
    node* el=new node(n);
    if(head==NULL){
        head=el;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=el;
    }
}
bool searching(node* head,int key){
    while(head->next!=NULL){
        if(head->data==key)
            return true;
        head=head->next;    
    }
    return false;
}
int main(){
    node* head=NULL;
    insertion(head,1);
    insertion(head,2);
    insertion(head,3);
    cout<<searching(head,2);
}
