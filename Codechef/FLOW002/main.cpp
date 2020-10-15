#include <iostream>

using namespace std;

int main()
{
    int i,n,a,b,rem;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a>>b;
	    rem=a%b;
	    cout<<rem<<endl;
	}
    return 0;
}
