#include "LatinSquare.h"
#include <iostream>
#include "Path.h"
using namespace std;


LatinSquare::LatinSquare(int n){
	this -> n = n;
	m = new int*[n];
	for (int i=0;i<n;i++){
		m[i] = new int[n];
	}
	for (int i=0;i<n;i++){
		for (int j=0; j<n;j++){
			m[i][j] = 0;
		}
	}
	c = 0;
}

void LatinSquare::calculate(){
	
	backTrack(0,0);
	
}

void LatinSquare::backTrack(int i, int j){
	
	if (i==n && j ==n{
		return;
	}
	
	int nextI=0;
	int nextJ=0;
	
	for (int x=1 ; x<=n;x++){
		if(c<40){
			c++;
		}
		else
			return;
		cout << " ---------------------------------- "<<endl;
		cout <<"BEFOR -> i and j and x are: "<<i<<" "<<j<<" "<<x<<endl;
		m[i][j] = x;
		
	
		//going to the next index, vertically
		
		
		if (i+1<n){
			nextI=i+1;
			nextJ=j;
		}
		else {
			nextJ=j+1;
			nextI=0;
		}
		//if check is ok then go to the next index, otherwise return to the previous step
	//	if (finalCheck())
			showMatrix();

			backTrack(nextI,nextJ);
			
			
	
	}
}

bool LatinSquare::finalCheck(){

	
	bool arr[n];
	
	//checking rows:
	for (int i=0;i<n;i++){
		//clearing the flag array:
		for (int i=0;i<n;i++){
			arr[i] = 0;
		}
		for (int j=0;j<n;j++){
			if (arr[m[i][j]] == true)
				return false;       //we already have a repetitive number, so it can not be true.
			arr[m[i][j]] = true;
		}
	}
	//checking columns:
	for (int j=0; j<n;j++){
		//clearing the flag array:
		for (int i=0;i<n;i++){
			arr[i] = 0;
		}
		for (int i=0;i<n;i++){
			if (arr[m[i][j]] == true)
				return false;       //we already have a repetitive number, so it can not be true.
			arr[m[i][j]] = true;
		}
	}
	return true;
}
bool LatinSquare::finished(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (m[i][j]!=n);
				return false;
		}
	}
	return true;
}
void LatinSquare::showMatrix(){
	cout << endl<<endl;
	for (int i=0;i<n;i++){
		for (int j=0; j<n;j++){
			printf("%5d",m[i][j]);
			
		}
		cout << endl;
	}
}
