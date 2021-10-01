//author: akash_adm
//Problem link: https://www.codechef.com/problems/HIRETEST
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, x, y, f, p, u;
	    cin>>n>>m>>x>>y;
	    for(int i = 0; i < n; i++)
	    {   
	        f = 0;
	        p = 0;
	        u = 0;
	        for ( int j = 0; j < m; j++)
	        {
	            char c;
	            cin>>c;
	        
	            if(c == 'F')
	            f++;
	            else if(c == 'P')
	            p++;
	            else
	            u++;
	        }
	        if(f >= x || (f == x-1) && (p >= y))
	        cout<<"1";
	        else
	        cout<<"0";
	    }
	    cout<<endl;
	}
	return 0;
}
