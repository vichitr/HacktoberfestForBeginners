#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void recover_util(node* root,node **first,node** mid,node** last,node** prev){
    if(root==NULL)
    return;
    recover_util(root->left,first,mid,last,prev);
    if(*prev && (*prev)->data>root->data){
        if(!*first){
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    recover_util(root->right,first,mid,last,prev);
}



void recover(node* root){
    node *first,*mid,*last,*prev;
    first=NULL;
    last=NULL;
    mid=NULL;
    prev=NULL;
    recover_util(root,&first,&mid,&last,&prev);
    if(first && last){
        swap(first->data,last->data);
    }
    else if(first && mid)
    swap(first->data,mid->data);    
}

void display(node* root){
    if(root==NULL)
    return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main(){
    node* root=new node(4);
    root->left=new node(6);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(2);
    display(root);
    cout<<endl;
    recover(root);
    display(root);
}