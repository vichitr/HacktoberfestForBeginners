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

int height(node* root){
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right)) + 1;
}

bool height_balance(node* root){
    if(root==NULL)
    return true;
    if(height_balance(root->left)==false)
    return false;
    if(height_balance(root->right)==false)
    return false;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}

bool height_balance_optimised(node* root,int *h){
    if(root==NULL){
        *h=0;
        return true;
    }
    int lh=0,rh=0;
    if(height_balance_optimised(root->left,&lh)==false)
    return false;
    if(height_balance_optimised(root->right,&rh)==false)
    return false;
    *h=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}

int main(){
    node* root2=new node(1);
    root2->left=new node(2);    
    root2->left->left=new node(3); 

    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);   
    cout<<height_balance(root)<<endl;
    int h=0;
    cout<<height_balance_optimised(root2,&h);
}