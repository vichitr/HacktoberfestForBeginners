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
    if(head==NULL)
        head=el;
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=el;
    }    
}

void insertion_head(node* &head,int n){
    node* el=new node(n);
    el->next=head;
    head=el;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

int main(){
    node* head=NULL;
    insertion(head,1);
    insertion(head,2);
    insertion(head,3);
    insertion_head(head,4);
    display(head);
}