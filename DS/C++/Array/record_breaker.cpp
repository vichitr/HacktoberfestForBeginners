#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=a[0];
    int count=0;
    if(a[0]>a[1]){
        count++;
    }
    for(int i=1;i<n-1;i++){
        if(a[i]>max && a[i]>a[i+1]){
            max=a[i];
            count++;        
        }
    }
    if(a[n-1]>max)
    count++;

    cout<<count;
}