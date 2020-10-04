//dr_baymax, Codeforces Round #645 (Div. 2)
#include<bits/stdc++.h>

using namespace std;
int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int max=0;int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int d=1;int i=n-1;
        for(;i>=0;i--){
            if(a[i]<=d+i)
                break;
        }
        cout<<d+i+1<<endl;
}
}