#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int d){
        left=NULL;
        right=NULL;
    }
};

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largest_bst(node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    return {1,root->data,root->data,1,true}; 

    info left=largest_bst(root->left);
    info right=largest_bst(root->right);
    info cur;
    cur.size=(1 + left.size + right.size);
    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data){
        cur.min=min(left.min,min(right.min,root->data));
        cur.max=max(right.max,max(left.max,root->data));
        cur.isBST=true;
        cur.ans=cur.size;
        return cur;
    }
    cur.isBST=false;
    cur.ans=max(left.ans,right.ans);    
    return cur;
}


int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    
    cout<<largest_bst(root).ans;    
}