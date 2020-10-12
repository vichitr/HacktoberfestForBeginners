#include <iostream>
#include<cmath>
#include <string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<assert.h>
#include<vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std ; 
vector<int> print(string str)
{
    stringstream s ; 
    s<< str ; 
    vector<int> res ; 
    int temp ; 
    char ch ;
    while(s>>temp){
        res.push_back(temp);
        s>>ch ;
    }
    return res ;
}
int main ()
{
    string s ; 
    cin >> s; 
    vector<int> vec = print(s);
    for(int i=0 ; i<vec.size() ; i++ )
        cout << vec[i] << endl; 
}
