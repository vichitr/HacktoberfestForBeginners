#include<bits/stdc++.h>
using namespace std;

int ispallin(string num){
    int flag=1;
    int l=num.size();
    for(int i=0;i<l/2;i++){
        if(num[i]!=num[l-1-i])
        flag=0;
    }
    return flag;
}

int subarray(int a[],int n,int k){
    string s="";
    for(int i=0;i<k;i++){
        s=s+to_string(a[i]);
    }
    if(ispallin(s))
    return 0;
    for(int i=k;i<n;i++){
        string s1=to_string(a[i-k]);
        int l=s1.size();
        s=s.substr(l,s.size()-l) + to_string(a[i]);        
        if(ispallin(s))
        return i-k+1; 
    }
    return -1;
}

int main(){
    int a[]={2,3,5,1,1,5};
    int n=6;
    int k=4;
    int pos=subarray(a,n,k);
    if(pos==-1)
    cout<<"NOt exist";
    else{
        for(int i=0;i<k;i++)
        cout<<a[i+pos]<<" ";
    }
}