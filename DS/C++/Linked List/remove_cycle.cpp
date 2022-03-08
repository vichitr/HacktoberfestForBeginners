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
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=el;
}

void create_cycle(node* &head, int pos){
    int c=1;
    node* temp=head;
    node* point=head;;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(point->next!=NULL && c<pos){
        point=point->next;
        c++;
    }
    if(c==pos){
        temp->next=point;
    }

}

int check_cycle(node* head){
    node* slowptr=head;
    node* fastptr=head;
    while(fastptr->next!=NULL && fastptr!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr)
            return 1;        
    }
    return -1;
}

void remove_cycle(node* head){
    node* slowptr=head;
    node* fastptr=head;
    do{
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }while(slowptr!=fastptr);
    fastptr=head;
    while(fastptr->next!=slowptr->next){
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    slowptr->next=NULL;
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
    int a[]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++){
        insertion(head,a[i]);
    }
    display(head);
    create_cycle(head,5);    
    cout<<check_cycle(head)<<endl;
    remove_cycle(head);
    cout<<check_cycle(head);
}