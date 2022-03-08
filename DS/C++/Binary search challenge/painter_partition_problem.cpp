#include<bits/stdc++.h>
using namespace std;

int isfisible(int a[],int n,int m, int mid){
    int sum=0,c=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>mid){
            c++;
            sum=a[i];
        }
        if(c>m)
        return 0;
    }
    return 1;
}

int painter_partition(int a[],int n,int m){
    int sum=0,k=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
        k=max(k,a[i]);
    }    
    int s=k,e=sum;
    while(s<e){
        int mid=(s+e)/2;
        if(isfisible(a,n,m,mid)){            
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}

int main(){
    int a[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<painter_partition(a,n,m);
}