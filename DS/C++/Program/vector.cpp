#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(auto element:arr){
        cout<<element<<" ";
    }
    cout<<endl;

    vector<int> arr2(4,20);
    swap(arr,arr2);
    arr.pop_back();
    for(auto element:arr)
        cout<<element<<" ";
}