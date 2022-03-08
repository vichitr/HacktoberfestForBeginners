#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int s;
    cin>>s;
    int i=0,j=m-1,flag=0;
    while(i<n && j>=0){
        if(a[i][j]==s){
            flag=1;
            break;
        }
        else if(a[i][j]<s)
            i++;
        else
            j--;    
    }
    if(flag=1)
        cout<<i<<" "<<j;
    else
        cout<<-1;    
}