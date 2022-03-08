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
node* delete_head(node* &head){
    if(head==NULL || head->next==NULL){
        delete head;
        return NULL;
    }    
    else{
        node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
}

node* deletion(node* &head,int key){
    if(head->data==key)
        return delete_head(head);
    else{
        node* temp=head;
        while(temp->next!=NULL){
            if(temp->next->data==key){
                node* del=temp->next;
                temp->next=del->next;
                delete del;
                return head;
            }
            temp=temp->next;
        }
        return head;
    }    
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
    insertion(head,4);
    head=deletion(head,5);
    display(head);
}