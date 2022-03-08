#include<bits/stdc++.h>
using namespace std;

int trapping_rainwater(vector<int> a,int n){
    stack<int> st;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int curr=st.top();
            st.pop();
            if(st.empty())
            break;
            int len=i-st.top()-1;
            ans+=(min(a[i],a[st.top()])-a[curr])*len;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    cout<<trapping_rainwater(a,n);
}