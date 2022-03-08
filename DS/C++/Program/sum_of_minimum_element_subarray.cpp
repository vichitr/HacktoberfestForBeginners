#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int pos=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[pos])
            pos=j;
        }
        swap(a[pos],a[i]);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,n);
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                sum=sum+a[k];
                break;
            }
        }
    }
    cout<<sum;
}