#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c, long m){
    long table[n+1][m];
    
    for(int j=0; j<m; j++)
        table[0][j]=1;
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<m; j++)
        {
            long x = (i-c[j]>=0) ? table[i-c[j]][j]:0;
            long y = (j>=1) ? table[i][j-1]:0;
            
            table[i][j]= x+y;
        }
    }
    return table[n][m-1];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c, m);
    cout<<ways<<endl;
    return 0;
}
