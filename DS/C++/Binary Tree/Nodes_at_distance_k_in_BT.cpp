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

void print_subtree(node* root,int k){
    if(root==NULL || k<0)
    return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    print_subtree(root->left,k-1);
    print_subtree(root->right,k-1);
}

int node_at_distance(node* root,node* target,int k){
    if(root==NULL)
        return -1;
    if(root==target){
        print_subtree(root,k);
        return 0;
    }
    int dl=node_at_distance(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k)
        cout<<root->data<<" ";
        else{
        print_subtree(root->right,k-dl-2);
        return 1+dl;
        }
    }
    int dr=node_at_distance(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k)
        cout<<root->data<<" ";
        else{
        print_subtree(root->left,k-dr-2);
        return 1+dr;
        }
    }
    return -1;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    node_at_distance(root,root->right,2);
}