#include<bits/stdc++.h>
using namespace std;
int printEqualSumSets(int arr[], int n) 
{ 
    int i, currSum; 
    int sum = accumulate(arr, arr+n, 0); 
    if (sum & 1) { 
        return -1; 
    } 
    int k = sum >> 1; 
    bool dp[n + 1][k + 1]; 
    for (i = 1; i <= k; i++) 
        dp[0][i] = false; 
    for (i = 0; i <= n; i++) 
        dp[i][0] = true; 
    for (i = 1; i <= n; i++) { 
        for (currSum = 1; currSum <= k; currSum++) { 
            dp[i][currSum] = dp[i - 1][currSum]; 
  
           if (arr[i - 1] <= currSum) 
                dp[i][currSum] = dp[i][currSum] |  
                  dp[i - 1][currSum - arr[i - 1]]; 
        } 
    } 
    
    if (!dp[n][k]) { 
        return -1; 
    } 
    else
    return 1;
       
} 
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        int res=printEqualSumSets(a,n); 
        if(res==-1)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
    }
}