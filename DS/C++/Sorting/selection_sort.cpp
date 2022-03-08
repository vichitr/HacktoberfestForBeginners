#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n){
    int pos,temp;
    for(int i=0;i<n-1;i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(a[pos]>a[j])
                pos=j;
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}