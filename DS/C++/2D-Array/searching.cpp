#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    int s,flag=0;
    cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==s){
                flag=1;
                cout<<"found at position "<<i<<" "<<j;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Not found";
}