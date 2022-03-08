#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int l=s.length();
    int freq[26]={0};
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<l;i++){
        if(s[i]>='a' && s[i]<='z')
            freq[s[i]-'a']++;
    }
    int mx=0,pos=0;
    for(int i=0;i<26;i++){
        if(freq[i]>mx){
            mx=freq[i];
            pos=i;
        }        
    }
    char c='a'+pos;
    cout<<c;
}