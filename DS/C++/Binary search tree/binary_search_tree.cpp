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

node* create_BST(node* root,int val){    
    if(root==NULL){
        return new node(val);        
    }
    if(root->data > val)
    root->left=create_BST(root->left,val);
    else if(root->data < val)
    root->right=create_BST(root->right,val);
    return root;
}

void display(node* root){
    if(root==NULL)
    return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int main(){
    node* root=NULL;
    root=create_BST(root,5);
    root=create_BST(root,1);
    root=create_BST(root,3); 
    root=create_BST(root,4);
    root=create_BST(root,2);   
    root=create_BST(root,7);
    display(root);
}