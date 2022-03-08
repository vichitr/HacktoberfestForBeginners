#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque<int> dq;
    cin>>k;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);
    for(int i=k;i<n;i++){
        if(dq.front()<=i-k)
        dq.pop_front();
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
    for(auto el:ans)
    cout<<el<<" ";
}