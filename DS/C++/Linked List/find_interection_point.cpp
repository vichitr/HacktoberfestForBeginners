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
void make_intersection(node* head,node* &head2,int pos){
    int c=1;
    while(head->next!=NULL && c<pos){
        c++;
        head=head->next;
    }
    node* temp=head2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
}

int find_intersection(node* head,node* head2){
    int l1=0;
    int l2=0;
    
    node* temp1=head;
    node* temp2=head2;
    while(temp1!=NULL){
        l1++;
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        l2++;
        temp2=temp2->next;
    }
    
    temp1=head;
    temp2=head2;
    int c=1;
    while(temp1!=NULL){
        if(c==(l1-l2))
            break;
        temp1=temp1->next;    
        c++;
    }
    temp1=temp1->next;
    while(temp1!=NULL){
        if(temp1==temp2)
            return temp1->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    node* head2=NULL;
    int a[]={1,2,3,4,5,6,7,8,9};
    int b[]={4,5,6};
    for(int i=0;i<9;i++){
        insertion(head,a[i]);
    }
    for(int i=0;i<3;i++){
        insertion(head2,b[i]);
    }
    display(head);    
    make_intersection(head,head2,7);
    display(head2);
    cout<<find_intersection(head,head2);
}