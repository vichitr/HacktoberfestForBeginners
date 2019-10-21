#include <bits/stdc++.h>
using namespace std;
using LL =long long;

int main() {
    LL n,k;
    cin>>n>>k;
    int a[n],i=1,j=0;
    string str;
    cin>>str;
    if(k==0)
        cout<<str;
    else if(n==1)
        cout<<0;
    else{
        if(str[0]=='1');
        else 
            str[0]='1',k--;
            
        while(j<k && i<n){
        if(str[i]!='0')str[i]='0',j++;
        i++;
        }
    cout<<str;
}
}
