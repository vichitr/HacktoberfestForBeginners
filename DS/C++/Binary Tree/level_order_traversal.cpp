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

void level_order_traversal(node* root){
    if(root==NULL)
    return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left !=NULL)
            q.push(temp->left);
            if(temp->right !=NULL)
            q.push(temp->right);
        }
        else if(!q.empty()){            
            q.push(NULL);
            cout<<endl;
        }
    }
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    level_order_traversal(root);
}