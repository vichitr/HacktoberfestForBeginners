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

void right_view(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){        
        int s=q.size();
        for(int i=0;i<s;i++){
            node* temp=q.front();
            q.pop();
            if(i==s-1)
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
    }
}
void right_view2(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int data;
    while(!q.empty()){        
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            data=temp->data;
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
        else if(!q.empty()){
            cout<<data<<" ";
            q.push(NULL);
        }
        else
        cout<<data;          
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
    right_view2(root);
}