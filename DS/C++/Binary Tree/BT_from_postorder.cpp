#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int n){
        data=n;
        left=NULL;
        right=NULL;
    }
};

int search(int in[],int curr,int start,int end){
    for(int i=start;i<=end;i++){
        if(in[i]==curr)
        return i;
    }
    return -1;
}
Node* create_tree(int post[],int in[],int start,int end){
    static int idx=end;
    if(start>end)
    return NULL;
    int cur=post[idx];
    idx--;
    Node* node=new Node(cur);
    if(start==end)
    return node;
    int pos=search(in,cur,start,end);
    node->right=create_tree(post,in,pos+1,end);
    node->left=create_tree(post,in,start,pos-1);
    return node;
}
void display(Node* node){
    if(node==NULL)
    return;
    display(node->left);
    cout<<node->data<<" ";
    display(node->right);
}

int main(){
    int post[]={4,2,5,3,1};
    int in[]={4,2,1,5,3};
    Node* root=create_tree(post,in,0,4);
    display(root);
}
