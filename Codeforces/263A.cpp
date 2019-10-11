#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,k,l;
	for( i=1;i<=5;i++){
	    for( j=1;j<=5;j++){
			cin >> n;
			if(n == 1){
			    k=i;
			    l=j;
			}
		}
	}
	cout << abs(3-k) + abs(3-l);
	
	return 0;
}
