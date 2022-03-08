/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((i+j)&1)
            cout<<0<<" ";
            else
            cout<<1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
