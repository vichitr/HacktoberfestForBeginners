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

int search_pos(int in[],int el,int l,int h){
    
    for(int i=l;i<=h;i++){
        if(in[i]==el)
        return i;
    }
    return -1;
}

node* create_tree(int in[],int pre[],int l,int h){
    static int idx=0;
    if(l>h){        
        return NULL;
    }
    int curr=pre[idx];
    idx++;
    node* root=new node(curr);
    if(l==h){
        return root;
    }
    int pos=search_pos(in,curr,l,h);
    root->left=create_tree(in,pre,l,pos-1);      
    root->right=create_tree(in,pre,pos+1,h);    
    return root;   
}

void inorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

int main(){
    int in[]={4,2,1,5,3};
    int pre[]={1,2,4,3,5};    
    node* root=create_tree(in,pre,0,4);
    inorder_traversal(root);
}