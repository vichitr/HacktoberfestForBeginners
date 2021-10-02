#include<bits/stdc++.h>
using namespace std;

void traversal(int size,int *a){
    for(int j=0;j<size;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

void bubblesort(int n,int *a){
    int temp;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }

        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting:"<<endl;
    traversal(n,arr);
    bubblesort(n,arr);
    cout<<"After sorting:"<<endl;
    traversal(n,arr);




    return 0;
}