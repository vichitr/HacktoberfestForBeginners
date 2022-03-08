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
        head->next=head;
    }
    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=el;
        el->next=head;
    }    
}

void insertion_head(node* &head,int n){
    node* el=new node(n);
    if(head==NULL){
        head=el;
        head->next=head;
    }
    el->next=head;
    node* temp=head;
    while(temp->next!=head){
            temp=temp->next;
        }
    temp->next=el;
    head=el;
}

void deletion(node* &head,int pos){
    int c=1;
    node* temp=head;
    while(temp->next!=head && c<pos-1){
        c++;
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}

void delete_head(node* &head){
    node* del=head;
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete del;
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
     
    cout<<"NULL";
}

int main(){
    node* head=NULL;
    insertion(head,1);
    insertion(head,2);
    insertion(head,3);
    insertion(head,5);
    insertion_head(head,4);
    deletion(head,3);
    delete_head(head);
    display(head);
}