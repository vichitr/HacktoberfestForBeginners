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

node* build_BST(int a[],int start,int end){
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    node* root=new node(a[mid]);
    root->left=build_BST(a,start,mid-1);
    root->right=build_BST(a,mid+1,end);
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
    int ar[]={10,20,30,40,50,60};
    
    node* root=build_BST(ar,0,5);
    display(root);
}
