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

bool check_bst(node* root,node* min,node* max){
    if(root==NULL)
    return true;
    if(min && root->data <min->data)
    return false;
    if(max && root->data > max->data)
    return false;
    bool left=check_bst(root->left,min,root);
    bool right=check_bst(root->right,root,max);
    return left && right;
}

int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(7);
    root->right->right=new node(6);
    cout<<check_bst(root,NULL,NULL);
}