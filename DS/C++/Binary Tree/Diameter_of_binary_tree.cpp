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

int diameter_of_bt(node* root,int* h){
    if(root==NULL){
        *h=0;
        return 0;
    }
    int lh=0,rh=0;
    int leftdiameter=diameter_of_bt(root->left,&lh);
    int rightdiameter=diameter_of_bt(root->right,&rh);
    int currdiamter=lh+rh+1;
    *h=max(lh,rh)+1;
    return max(currdiamter,max(rightdiameter,leftdiameter));
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int h=0;
    cout<<diameter_of_bt(root,&h);
}