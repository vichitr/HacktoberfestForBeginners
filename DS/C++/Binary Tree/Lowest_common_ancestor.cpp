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

node* Lca(node* root,int a,int b){
    if(root==NULL)
    return NULL;
    if(root->data==a||root->data==b)
    return root;
    node* left=Lca(root->left,a,b);
    node* right=Lca(root->right,a,b);
    if(left!=NULL && right!=NULL)
    return root;
    if(left==NULL && right==NULL)
    return NULL;
    if(left!=NULL)
    return Lca(root->left,a,b);
    if(right!=NULL)
    return Lca(root->right,a,b);
}

bool getpath(node* root,int a,vector<int> &path){
    if(root==NULL)
    return 0;
    path.push_back(root->data);
    if(root->data==a)
    return 1;
    if(getpath(root->left,a,path) || getpath(root->right,a,path))
        return 1;
    path.pop_back();    
    return 0;
}
int lowest_common_ancestor(node* root,int a,int b){
    vector<int> path1,path2;

    if(!getpath(root,a,path1) || !getpath(root,b,path2))
        return -1;
    int i;    
    for(i=0;i<path1.size() && path2.size();i++){
        if(path1[i]!=path2[i])
        break;
    }
    return path1[i-1];
}



int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int ans=lowest_common_ancestor(root,6,7);
    if(ans==-1)
    cout<<"Not exist"<<endl;
    else
    cout<<ans<<endl;
    node* ans2=Lca(root,6,7);
    if(root==NULL)
    cout<<"not exist";
    else
    cout<<ans2->data;
}