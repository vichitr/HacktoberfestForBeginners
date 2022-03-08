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

void append(node* &head,int pos){
    node* temp=head;
    int l=1;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    node* point=head;
    int c=1;
    while(point->next!=NULL &&  c<l-pos){
        c++;
        point=point->next;
    }
    temp->next=head;
    head=point->next;
    point->next=NULL;

}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
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
    display(head);
    append(head,3);
    display(head);
}