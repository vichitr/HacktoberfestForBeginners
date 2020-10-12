#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {  

vector <int> vec ;
int n,x ; 
cin >> n ; 
for (int i =0 ; i<n ; i++) 
{
    cin >> x ; 
    vec.push_back(x) ;
}
sort(vec.begin(),vec.end()) ; 
for (int i=0 ; i<vec.size() ; i++) 
    cout << vec.at(i) << " " ;

return 0;
}
