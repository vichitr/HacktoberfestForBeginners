#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+i])
            swap(a[j],a[j+1]);
        }
    }
}

int main(){
    int n,rsum;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,n);
    cin>>rsum;
    int i=0,j=a[n-1];
    while(i<j){
        if((a[i]+a[j])==rsum)
        {
            cout<<a[i]<<" "<<a[j];
            break;            
        }
        else if(a[i]+a[j]>rsum)
            j--;
        else
            i++;
    }
}