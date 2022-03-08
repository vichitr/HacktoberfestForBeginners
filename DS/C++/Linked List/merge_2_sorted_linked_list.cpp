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

node* merge(node* head1,node* head2){
    node* dummy=new node(0);
    node* dummy_head=dummy;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            dummy->next=head1;
            head1=head1->next;
        }
        else{
            dummy->next=head2;
            head2=head2->next;
        }
        dummy=dummy->next;
    }
    while(head1!=NULL){
        dummy->next=head1;
        head1=head1->next;
        dummy=dummy->next;
    }
    while(head2!=NULL){
        dummy->next=head2;
        head2=head2->next;
        dummy=dummy->next;
    }
    return dummy_head->next;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    int a[]={1,3,5,7,9};
    int b[]={2,4,6,8};
    for(int i=0;i<5;i++){
        insertion(head1,a[i]);
    }
    for(int i=0;i<4;i++){
        insertion(head2,b[i]);
    }
    display(head1);
    display(head2);
    node* new_head=merge(head1,head2);
    display(new_head);
}