#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int n){
        data=n;
        prev=NULL;
        next=NULL;
    }
};

void insertion_head(node* &head,int n){
    node* el=new node(n);
    if(head==NULL){
        head=el;
        return;
    }
    head->prev=el;
    el->next=head;
    head=el;
}
void insertion(node* &head,int n){
    if(head==NULL){
        insertion_head(head,n);
        return;
    }
    node* el=new node(n);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=el;
    el->prev=temp;
}

void deletion(node* &head,int pos){
    node* temp=head;
    int c=1;
    while(temp->next!=NULL && c<pos){
        c++;
        temp=temp->next;
    }
    
    if(c==pos){
        node* del=temp;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete del;
    }
}

void delete_head(node* &head){
    node* temp=head;
    head->next->prev=NULL;
    head=head->next;
    delete temp;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"<->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int a[]={1,2,3,4,5,6};
    node* head=NULL;
    for(int i=0;i<6;i++){
        insertion(head,a[i]);
    }
    insertion_head(head,0);
    display(head);
    deletion(head,4);
    delete_head(head);
    display(head);
}