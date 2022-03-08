#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int c=1;
        while(!st.empty() && st.top().first<a[i]){
            c+=st.top().second;
            st.pop();
        }
        ans.push_back(c);
        st.push({a[i],c});
    }
    for(auto el:ans)
    cout<<el<<" ";
}