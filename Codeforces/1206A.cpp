#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using LL =long long;

int main()
  {
    LL n,m;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A)cin>>a;
    cin>>m;
    vector<int> B(m);
    for(auto &b:B)cin>>b;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    cout<<A[n-1]<<" "<<B[m-1];

}
      
