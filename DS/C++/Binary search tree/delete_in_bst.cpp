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
node* succesor(node* root){
    node* temp=root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* delete_bst(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data >val)
    root->left= delete_bst(root->left,val);
    else if(root->data < val)
    root->right= delete_bst(root->right,val);
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* s=succesor(root->right);
        root->data=s->data;
        root->right=delete_bst(root->right,s->data); 
    }
    
    return root;
}

void display(node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
    
}
int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    display(root);
    cout<<endl;
    root=delete_bst(root,6);
    display(root);
}