#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    unsigned int a[3],A=0;
    unsigned int b[3],B=0;
    for (int i = 0; i<3;i++) cin>>a[i];
    for(int j =0;j<3;j++)
    {
        cin>>b[j];
        
        if (a[j]>b[j]) A++;
        else if (a[j]<b[j]) B++;
        else ;
    }
    cout<<A<<" "<<B<<endl;
    return 0;
}
