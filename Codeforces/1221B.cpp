#include <bits/stdc++.h>
using namespace std;
using LL =long long;
 
int main() {
    LL t,i=0;
    cin>>t;
    char a[t][t];
    while(i<t){
            int j=0;
            if(i%2==0)while(j<t)
            { 
                if(j%2==0)
                a[i][j]='W';
                else
                a[i][j]='B';
                j++;
            }
            else
            for(int y=0;y<t;y++)
            { 
                if(y%2==0)
                a[i][y]='B';
                else
                a[i][y]='W';
            }
            i++;
    }
    
       for(int i=0;i<t;i++){
       for(int j=0;j<t;j++)cout<<a[i][j];
       cout<<endl;
       }
}
