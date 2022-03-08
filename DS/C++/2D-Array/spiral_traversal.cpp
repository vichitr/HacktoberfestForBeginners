#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i;
    cin>>n>>m;
    int a[n][m];
    for(i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    int row_start=0,row_end=n-1,col_start=0,col_end=m-1;

    while(row_start<=row_end && col_start<=col_end){
        for(i=col_start;i<=col_end;i++)
            cout<<a[row_start][i]<<" "<<endl;
        row_start++;
        for(i=row_start;i<=row_end;i++)
            cout<<a[i][col_end]<<" "<<endl;
        col_end--;
        for(i=col_end;i>=col_start;i--)
            cout<<a[row_end][i]<<" "<<endl;
        row_end--;
        for(i=row_end;i>=row_start;i--)
            cout<<a[i][col_start]<<" "<<endl;  
        col_start++;      
    }

}