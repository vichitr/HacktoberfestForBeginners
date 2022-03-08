#include<bits/stdc++.h>
using namespace std;

int subarraydivisible(int a[],int n,int k){
    string s="";
    int num=-1;
    for(int i=0;i<k;i++){
        s=s+to_string(a[i]);        
    }
    if(stoi(s)%3==0)
    num=stoi(s);
    for(int i=k;i<n;i++){
        string s1=to_string(a[i-k]);  
        int l1=s1.size();      
        s=s.substr(l1,(s.size()-l1)) + to_string(a[i]);        
        if(stoi(s)%3==0)
        num=stoi(s);
    }
    return num;
}

int main(){
    int a[]={8,23,45,12,56,4};
    int n=6;
    int k=3;
    cout<<subarraydivisible(a,n,k);
}