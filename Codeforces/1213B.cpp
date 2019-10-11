#include <bits/stdc++.h>

using namespace std;

void testcase(){
	int n;
	cin >> n;
	vector<int> price(n);
	for(int i=0;i<n;i++)
	    cin>>price[i];
	int min = price.back();
	int bad_day = 0;
	
	for(int i=n-2;i>=0;i--){
		if(price[i] > min){
			bad_day++;
		}
		else
		    min = price[i];
	}
	
	cout << bad_day;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		testcase();
		cout << "\n";
	}
	
	
	return 0;
}
