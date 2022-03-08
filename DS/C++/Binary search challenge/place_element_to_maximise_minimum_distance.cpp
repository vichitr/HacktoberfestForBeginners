#include<bits/stdc++.h>
using namespace std;

bool isfesible(int a[],int n,int k,int mid){
    int c=1,pos=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-pos >= mid){
            c++;
            pos=a[i];
            if(c==k)
                return 1;
        }
    }
    return 0;
}
int max_min_distance(int a[],int n,int k){
    sort(a,a+n);
    int start=1,end=a[n-1],result=-1;
    while(start<end){
        int mid=(start+end)/2;
        if(isfesible(a,n,k,mid)){
            result=max(result,mid);
            start=mid+1;
        }
        else
            end=mid;
    }
    return result;
}

int main(){
    int a[]={1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<max_min_distance(a,n,k);
}