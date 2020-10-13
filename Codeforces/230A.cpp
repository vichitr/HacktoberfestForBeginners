//CODEFORCES Round 142 Div.2
//Problem A

#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int S,N,i; 
    cin>>S>>N;
    vector<pair<int,int>>Dragon;
    for(i=0;i<N;i++) 
    {
        int X,Y; 
        cin>>X>>Y;
        Dragon.push_back({X,Y});
    }
    sort(Dragon.begin(),Dragon.end());
    for(i=0;i<N;i++) 
    {
        if(Dragon[i].first<S) 
        {
            S+=Dragon[i].second;
        }
        else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}