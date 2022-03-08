#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int i,int n){
    int largest=i;
    int lchild=2*i +1;
    int rchild=2*i +2;
    if(lchild<n && a[lchild]>a[largest])
    largest=lchild;
    if(rchild<n && a[rchild]>a[largest])
    largest=rchild;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
void heapsort(int a[],int n){
    for(int i=n/2 -1;i>=0;i--){
        heapify(a,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

int main(){
    int a[]={4,5,3,2,6,1};
    int n=6;
    heapsort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}