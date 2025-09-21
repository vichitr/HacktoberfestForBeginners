#include <iostream>
using namespace std;

void dnf_sort(int ar[], int n){
	int high = n-1;
	int low = 0;              /// 3 pointer approach ...
	int mid = 0;

	while(mid <= high)
	{
		if(ar[mid] == 1)
		{
			mid++;
		}
		else if(ar[mid] == 2)
		{
			swap(ar[mid],ar[high]);
			high--;
		}
		else
		{
			swap(ar[mid],ar[low]);
			mid++;
			low++;
		}

	}
}
	
int main(){
	int ar[]={1,0,0,2,2,1,0,2,0,1,1,0,2};
	int n = sizeof(ar)/sizeof(int);
	dnf_sort(ar,n);
	for(int i=0; i<n; i++){
		cout << ar[i] << " ";
	}
}