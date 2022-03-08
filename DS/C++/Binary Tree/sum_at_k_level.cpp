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

int sum_at_level(node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int lvl=0;
    int sum=0;
    while(!q.empty() && lvl<=k){
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            if(lvl==k)
            sum+=temp->data;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            lvl++;
        }
    }
    return sum;
}


int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int k;
    cin>>k;
    cout<<sum_at_level(root,k);
}