#include<bits/stdc++.h>
using namespace std;

int count_path(int s,int e){
    if(s>e)
    return 0;
    if(s==e)
    return 1;
    int count=0;
    for(int i=1;i<=6;i++){
        count+=count_path(s+i,e);
    }
    return count;
}

int main(){
    int s,e;
    cin>>s>>e;
    cout<<count_path(s,e);
}