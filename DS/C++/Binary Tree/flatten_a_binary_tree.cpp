#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int n){
        data=n;
        left=NULL;
        right=NULL;
    }
};

void flatten_tree(node* root){
    if(root==NULL)
    return;
    node* temp;
    flatten_tree(root->left);
    if(root->left!=NULL){
        temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node* t=root;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    if(temp!=NULL)
    flatten_tree(temp);
}

void display(node* root){
     while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
}
void inorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    inorder_traversal(root);
    cout<<endl;
    flatten_tree(root);
    display(root);
}