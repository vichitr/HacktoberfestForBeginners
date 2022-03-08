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

int max_sum_pathutil(node* root,int &ans){
    if(root==NULL)
    return 0;
    int ls=max_sum_pathutil(root->left,ans);
    int rs=max_sum_pathutil(root->right,ans);
    int curr=max(max((ls+rs+root->data),root->data),max((ls+root->data),(rs+root->data)));
    ans=max(ans,curr);
    return max((root->data),max((ls+root->data),(rs+root->data)));
}

int max_sum_path(node* root){
    int ans=INT_MIN;
    max_sum_pathutil(root,ans);
    return ans;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<max_sum_path(root);
}