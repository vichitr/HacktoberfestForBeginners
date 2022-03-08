#include<bits/stdc++.h>
using namespace std;

int pivot(int a[],int l,int r){
    int pi=r;
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<a[pi]){
            swap(a[j],a[++i]);            
        }
    }
    swap(a[pi],a[++i]);
    return i;
}

void quicksort(int a[],int l,int r){
    if(l<r){
        int pi=pivot(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}