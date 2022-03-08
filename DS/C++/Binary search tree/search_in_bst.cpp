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

node* search_BST(node* root,int val){
    if(root==NULL)
    return NULL;
    if(root->data==val)
    return root;
    if(root->data > val)
    return search_BST(root->left,val);
    return search_BST(root->right,val);
}

int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    if(search_BST(root,6)==NULL)
    cout<<"NOt is BST";
    else
    cout<<search_BST(root,6)->data;
}