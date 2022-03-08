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

int cal_height(node* root){
    if(root==NULL)
    return 0;
    int lh=cal_height(root->left);
    int rh=cal_height(root->right);
    return max(lh,rh)+1;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<cal_height(root);
}