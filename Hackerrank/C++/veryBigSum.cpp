#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n;
        cin>>n;
    long sum=0;
    long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
    }
    cout<<sum;
    return 0;
}
