#include <bits/stdc++.h> 
#include<vector>
using namespace std; 
  
// Function to display the array 
int modulo(int a[],int n) 
{ 
    int modu=a[0],i;
    for(i=1;i<n;i++)
    {
        modu=modu%a[i];
    }
    return modu;
} 
  
// Function to find the permutations 
int findPermutations(int a[], int n) 
{ 
    int max=0;
    // Sort the given array 
    sort(a, a + n); 
  
    // Find all possible permutations 
    do { 
        int modu=modulo(a,n); 
        if(modu>max)
        max=modu;
    } while (next_permutation(a, a + n)); 
return max;
} 
  
// Driver code 
int main() 
{ 
  
    int i,p,a[1000],n,t;
    cin>>t;
    for(p=0;p<t;p++)
    {
        cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    
    int ans=findPermutations(a, n); 
    cout<<ans;
    }
    return 0; 
} 