#include<bits/stdc++.h>
using namespace std;

void heapify_up(vector<int> &mxheap,int n){
    int parent=(n-1)/2;
    if(mxheap[n]>mxheap[parent]){
        swap(mxheap[n],mxheap[parent]);
        if(parent!=0)
        heapify_up(mxheap,parent);
    }
}

void insert(vector<int> &mxheap,int num){
    mxheap.push_back(num);
    int l=mxheap.size();
    heapify_up(mxheap,l-1);
}

void heapify(vector<int> &mxheap,int root,int n){    
    int largest=root;
    int lchild=root*2 + 1;
    int rchild=root*2 + 2;    
    if(lchild<n && mxheap[lchild]>mxheap[largest])
    largest=lchild;
    if(rchild<n && mxheap[rchild]>mxheap[largest])
    largest=rchild;    
    if(largest!=root){
        swap(mxheap[root],mxheap[largest]);
        heapify(mxheap,largest,n);
    }
}
void deletion(vector<int> &mxheap){
    int l=mxheap.size();
    swap(mxheap[0],mxheap[l-1]);
    mxheap.pop_back();
    heapify(mxheap,0,l);
}
int main(){
    vector<int> mxheap;
    int a[]={5,7,3,2,9,6};    
    for(int i=0;i<6;i++){
        insert(mxheap,a[i]);
    }
    for(auto el:mxheap)
    cout<<el<<" ";
    cout<<endl;
    deletion(mxheap);
    for(auto el:mxheap)
    cout<<el<<" ";
    cout<<endl;
}