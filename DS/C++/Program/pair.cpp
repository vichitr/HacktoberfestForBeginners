#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    int n;
    cin>>n;
    int a;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }       
    
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        p.push_back(make_pair(arr[i],i));
    }
    sort(p.begin(),p.end(),mycompare);
    for(int i=0;i<n;i++){
        arr[p[i].second]=i;
    }
    for(auto element:arr){
        cout<<element<<" ";
    }
}