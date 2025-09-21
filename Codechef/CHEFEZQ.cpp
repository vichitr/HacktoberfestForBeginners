#include <iostream>
#define max 100000
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n;
	long long a[max],k,i;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    if(n==1)
	    {
	        cout<<(a[0]/k)+1<<"\n";
	    }
	    else{
	    for(i=0;i<n-1;i++)
	    {
	        if(a[i]<k) {cout<<i+1<<"\n";break;}
	        
	        else if(a[i]>k){
	            a[i+1]+=a[i]-k;
	        }
	        else{continue;}
	    }
	    
	    if(i==n-1) {
	    if(a[i]<k)   
	   {cout<<i+1<<"\n";}
	    else{
	        cout<<i+(a[i]/k)+1<<"\n";
	    }
	        
	    }
	}
	}
	// your code goes here
	return 0;
}

