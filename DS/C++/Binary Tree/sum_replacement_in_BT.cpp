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

void sum_replacement(node* root){
    if(root==NULL)
    return;
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->left!=NULL)
    root->data+=root->left->data;
    if(root->right!=NULL)
    root->data+=root->right->data;
    
}
void display(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    sum_replacement(root);
    display(root);
}