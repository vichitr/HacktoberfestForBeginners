// author: Ujjwal Raj

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    int allPos=1;
    int allNeg=1;
    int zeroPre=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>0)allNeg=0;
        if(arr[i]<0)allPos=0;
        if(arr[i]==0)zeroPre=1;
    }
    sort(arr.begin(),arr.end());
    int a1=1;
    int a2=1;
    if(zeroPre){
        if(allPos){
            a1=arr[0]*arr[0];
            a2*=arr.back();
            a2*=arr.back();
        }else if(allNeg){
            a1=0;
            a2=arr[0]*arr[0];
        }else{
            a1*=arr.back();
            a1*=arr[0];
            int temp=max(abs(arr[0]),abs(arr.back()));
            a2*=temp*temp;
        }
    }else{
        if(allPos){
            a1=arr[0]*arr[0];
            a2*=arr.back();
            a2*=arr.back();
        }else if(allNeg){
            a1*=arr.back();
            a1*=arr.back();
            a2=arr[0]*arr[0];
        }else{
            a1*=arr.back();
            a1*=arr[0];
            int temp=max(abs(arr[0]),abs(arr.back()));
            a2*=temp*temp;
        }
    }
    cout<<a1<<" "<<a2<<"\n";
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);

   int _t;cin>>_t;while(_t--)
   solve();
}