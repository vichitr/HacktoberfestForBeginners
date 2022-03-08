#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m,n1,c=0,sum=0;
    cin>>m>>n1;
    for(int i=0;i<n1;i++)
        sum=sum+a[i];  
    int p1=0,p2=n1-1;
    while(p2<n){
        if(sum==m)
        c++;
        p2++;
        sum=sum+a[p2]-a[p1];
        p1++;
    } 
    cout<<c;     
}