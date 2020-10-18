#include<iostream>
using namespace std;
int main(){
int arr[100] = {5,2,7,1,3};
int n = 5;
for(int i=0;i<n-1;i++){
    int curr = arr[i+1];
    int j = i;
    while(j>=0 && arr[j]>curr){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = curr;
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
