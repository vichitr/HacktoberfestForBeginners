#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,l=0,r=0;
    string s;
    cin>>n>>s;
    if(n%2!=0)
    {
        cout<<"No";
        return 0;
    }
    stack<char>k;
    for(int i=0;i<n;i++)
    {
        if((!k.empty()) && k.top()=='(' && s[i]==')')
        {
            k.pop();
        }
        else
        {
            k.push(s[i]);
        }

        if(s[i]==')')
        {
            l++;
        }
        else
        {
            r++;
        }
    }
    if(l!=r)
    {
        cout<<"No";
        return 0;
    }
    long cnt=0;
    while(!k.empty())
    {
        k.pop();
        cnt++;
        if(cnt>2)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
