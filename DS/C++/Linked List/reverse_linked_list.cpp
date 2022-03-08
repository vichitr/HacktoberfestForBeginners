#include<bits/stdc++.h>
using  namespace std;

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
        return;  
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=el;
}
node* reverse(node* &head){
    node* prev=NULL;
    node* current=head;
    node* next;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

node* reverse_rec(node* &head){
    if(head==NULL ||head->next==NULL)
        return head;
    node* newhead=reverse_rec(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<endl;
}



int main(){
    node* head=NULL;
    int a[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
       insertion(head,a[i]);
    }    
    display(head);
    head=reverse_rec(head);
    display(head);
}