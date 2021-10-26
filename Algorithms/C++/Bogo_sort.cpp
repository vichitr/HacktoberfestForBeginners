// C++ implementation of Bogo Sort 
#include<bits/stdc++.h> 
using namespace std; 

// To check if array is sorted or not 
int isSorted(int a[], int n) 
{ 
	while ( --n > 1 ) 
		if (a[n] < a[n-1]){ 
			return 0;} 
	return 1; 
} 

// To generate permuatation of the array 
void shuffle(int a[], int n) 
{ 
	for (int i=0; i < n; i++) 
		swap(a[i], a[rand()%n]); 
} 

// Sorts array a[0..n-1] using Bogo sort 
void bogosort(int a[], int n) 
{ 
	// if array is not sorted then shuffle 
	// the array again 
	while ( !isSorted(a, n) ) 
		shuffle(a, n); 
} 

// prints the array 
void printArray(int a[], int n) 
{ 
	for (int i=0; i<n; i++) 
		cout<<a[i]; 
	cout<<endl; 
} 

// Driver code 
int main() 
{ 
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
          cin>>a[i];}
	bogosort(a, n); 
	cout<<"Sorted array"; 
	printArray(a,n); 
	return 0; 
} 
