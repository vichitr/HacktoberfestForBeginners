//problem picked from Novemeber Easy 19
#include <bits/stdc++.h> 
using namespace std; 
  
// function to find and print duplicates 
void printDuplicates(int arr[], int n) 
{ 
    // unordered_map to store frequencies 
    vector<int > v;
    unordered_map<int, int> freq; 
    for (int i=0; i<n; i++) 
        freq[arr[i]]++; 
  
    bool dup = false; 
    unordered_map<int, int>:: iterator itr; 
    for (itr=freq.begin(); itr!=freq.end(); itr++) 
    { 
        // if frequency is more than 1 
        // print the element 
        if (itr->second == 1) 
        { 
            v.push_back(itr->first);
            dup = false; 
        } 
    } 
    sort(v.begin(), v.end());
    for (auto x : v) 
        cout << x << " ";   
    // // no duplicates present 
    // if (dup == false) 
    //     cout << itr->first; 
} 
  
// Driver program to test above 
int main() 
{ 
    int n,q,p;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printDuplicates(a,n);
    return 0;
} 
