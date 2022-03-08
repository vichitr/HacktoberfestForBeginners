#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    int rsum;
    cin>>rsum;
    int i=0,j=0,sum=0;
    while(i<=j && j<n){              
        sum=sum+a[j];
        while(sum>rsum){
                sum=sum-a[i];
                i++;
            }
        if(sum==rsum){
            break;
        }             
        j++;    
        
    }
    if(sum==rsum)
    cout<<i<<" "<<j;
    else
    cout<<-1;
}