#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);       //for faster I/O.
    cin.tie(0);
    cout.tie(0);

    long long n,x,e=0,o=0;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;

        if(x%2==0)
        {
            e++;
        }
        else
        {
            o++;
        }
    }

    cout<<min(o,e);

    return 0;
}
