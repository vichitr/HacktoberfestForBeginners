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

node* lca(node* root,int a,int b){
    if(root==NULL)
    return NULL;

    if(root->data==a || root->data==b)
        return root;

    node* left=lca(root->left,a,b);
    node* right=lca(root->right,a,b);
    if(left==NULL && right==NULL)
    return NULL;
    if(left!=NULL && right!=NULL)
    return root;

    if(left!=NULL)
    return lca(root->left,a,b);

    if(right!=NULL)
    return lca(root->right,a,b);    
}

int finddist(node* root,int a,int h){
    if(root==NULL)
        return -1;
    if(root->data==a)
        return h;
    int ld=finddist(root->left,a,h+1);
    if(ld!=-1)
        return ld;
    return finddist(root->right,a,h+1);
}

int shortest_distance(node* root,int a,int b){
    node* common=lca(root,a,b);
    if(common==NULL){
        return -1;
    }
    int lh=finddist(common,a,0);
    int rh=finddist(common,a,0);
    return lh+rh;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int sd=shortest_distance(root,7,5);
    if(sd==-1)
    cout<<"not exist";
    else
    cout<<sd;
}