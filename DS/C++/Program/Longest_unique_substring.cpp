#include<bits/stdc++.h>
using namespace std;

int longest_unique_substring(string s){
    int l=s.length();
    vector<int> idx(256,-1);
    int start=-1,maxlen=0;
    for(int i=0;i<l;i++){
        if(idx[s[i]]>start)
        start=idx[s[i]];
        
        idx[s[i]]=i;
        
        maxlen=max(maxlen,i-start);        
    }
    return maxlen;
}

int main(){
    string s;
    cin>>s;
    cout<<longest_unique_substring(s);
}