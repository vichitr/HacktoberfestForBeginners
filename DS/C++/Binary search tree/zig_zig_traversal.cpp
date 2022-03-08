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

void zigzag(node* root){
    stack<node*> stck1;
    stack<node*> stck2;
    stck1.push(root);
    bool leftright=true;
    while(!stck1.empty()){
        node* temp=stck1.top();
        stck1.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(leftright){
                if(temp->left)
                stck2.push(temp->left);
                if(temp->right)
                stck2.push(temp->right);
            }
            else{
                if(temp->left)
                stck2.push(temp->left);
                if(temp->right)
                stck2.push(temp->right);
            }
        }
        if(stck1.empty() && !stck2.empty()){
            leftright=!leftright;
            swap(stck1,stck2);
            cout<<endl;
        }
    }
}
int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    zigzag(root);
}