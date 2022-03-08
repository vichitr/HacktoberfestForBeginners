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


void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}
void change_order(node* &head){
    if(head==NULL || head->next==NULL)
        return;
    node* evenptr=head->next; 
    node* even=evenptr;   
    node* oddptr=head;
    while(evenptr->next!=NULL && oddptr->next!=NULL){
        oddptr->next=evenptr->next;
        oddptr=oddptr->next;
        evenptr->next=oddptr->next;
        evenptr=evenptr->next;
    }
    if(oddptr->next==NULL)
        evenptr->next=NULL;
    oddptr->next=even;    
}

int main(){
    node* head=NULL;
    int a[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertion(head,a[i]);
    }
    change_order(head);
    display(head);
}