#include<bits/stdc++.h>
using namespace std;

int search_rotated_array(int a[],int start,int end,int key){ 

    int mid=(start+end)/2;
    if(a[mid]==key)
        return mid;
    if(a[start]<=a[mid]){
        if(key >=a[start] && key<=a[mid])
            return search_rotated_array(a,0,mid-1,key);
        else
            return search_rotated_array(a,mid+1,end,key);    
    }
    else{
        return search_rotated_array(a,mid+1,end,key);
    }
}

int main(){
    int a[]={6,7,8,9,10,1,2,5};
    int n=8;
    int key=8;
    int idx=search_rotated_array(a,0,n,key);
    if(idx==-1)
    cout<<"Not found";
    else
    cout<<"found at position :" <<idx+1;
}