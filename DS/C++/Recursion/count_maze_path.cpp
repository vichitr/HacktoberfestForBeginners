#include<bits/stdc++.h>
using namespace std;

int count_maze_path(int i,int j,int n,int m){
    if(i>n || j>m)
    return 0;
    if(i==(n-1) && j==(m-1))
    return 1;
    return count_maze_path(i+1,j,n,m) + count_maze_path(i,j+1,n,m);
}
int main(){
    int n,m;
    cin>>n>>m;
    int i,j;
    cin>>i>>j;
    cout<<count_maze_path(i,j,n,m);
}