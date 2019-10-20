#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int rem[k]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        rem[x%k]++;
    }int count = 0;
    count += min(rem[0],1);
    if(k%2 != 0){
        for(int i=1;i<(k/2)+1;i++){
            count += max(rem[i],rem[k-i]);
        }
    }
    else{
        for(int i=1;i<k/2;i++){
            count += max(rem[i],rem[k-i]);
        }
        count += 1;
    }
    cout<<count;
    return 0;
}
