#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
 int n ; 
    cin >> n ; 
 int arr[n] ; 
    for (int i=0 ; i<n ; i++)
        cin >>arr[i] ; 
    for (int i=0 ; i<n/2 ; i++)
    {
      swap(arr[i],arr[n-i-1]) ; 
         
    }
    for (int i=0 ; i<n ;i++)
        cout << arr[i] << " " ; 
    return 0;
}
