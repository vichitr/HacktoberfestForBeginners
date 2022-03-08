#include<bits/stdc++.h>
using namespace std;

void wave_sort(int arr[],int n){

    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1])
            swap(arr[i],arr[i-1]);
        if(i<=n-2 && arr[i]>arr[i+1])
        swap(arr[i+1],arr[i]);    
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    wave_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}