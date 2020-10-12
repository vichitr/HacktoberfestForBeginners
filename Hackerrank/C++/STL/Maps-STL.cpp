#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
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
#include <numeric>
#include<array>
#include<tuple>
#include <utility>
#include <functional> 
#include <locale>  

using namespace std ; 
int main ()
{   
map< string , int > mp ; 
int q ;
cin >> q ;
string s ; 
int mark ; 
int type ; 
for (int i=0 ;i<q ; i++) {
    cin >> type  ; 
    if (type==1){  
      cin >>s>> mark ;  
      mp[s] += mark ;        
    }
    else if (type==2){  
        cin >> s ; 
        mp[s] = 0; 
           }
    else if (type==3){   
        cin >> s ;
        cout << mp[s] << endl ;   
          }
 }
}
