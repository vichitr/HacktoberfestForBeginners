#include <bits/stdc++.h>
using namespace std;
using LL =long long;

int main() {
    LL n,a,b;
    cin>>n;
    string str;
    cin>>str;
    unordered_map<char,int> um;
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        if (ch=='n')cout<<1<<" ";
    }
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        if (ch=='z')cout<<0<<" ";
    }
}
