#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x>>y;
        if(x==y) {cout<<"YES"<<"\n";}
        else{
        int p=(x+k)%n;
        while(p!=x&&p!=y)
        {
            p=(p+k)%n;
        }
        if(p==x)
        {cout<<"NO"<<"\n";}
        else{
         cout<<"YES"<<"\n";
        }
    
            
        }
    }
	// your code goes here
	return 0;
}

