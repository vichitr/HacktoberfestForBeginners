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

node* createBST(int pre[],int *pos,int key,int n,int min,int max){
    if(*pos>=n)
    return NULL;
    node* root=NULL;
    if(key>min && key<max){
        root=new node(key);
        *pos=*pos+1;
        if(*pos<n)
        root->left=createBST(pre,pos,pre[*pos],n,min,root->data);
        if(*pos<n)
        root->right=createBST(pre,pos,pre[*pos],n,root->data,max);
    }

    return root;
}

void display(node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main(){
    int pre[]={4,2,1,3,5,6};
    int pos=0;
    node* root=createBST(pre,&pos,pre[0],6,INT_MIN,INT_MAX);
    
    display(root);
}