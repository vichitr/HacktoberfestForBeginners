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

using namespace std ;
int main () 
{
int q ; 
cin >> q ;
int type ;
int x ;
set<int> st ; 
for (int i=0 ; i < q ; i++) {
    cin >> type ; 
    if (type==1){
        cin >> x ; 
        st.insert(x) ;       
    }
    else if (type==2){
        cin >> x; 
        st.erase(x) ; 
    }
    else if (type==3){
        cin >> x ; 
        if (st.count(x))
            cout << "Yes" << endl ;
        else 
            cout << "No" << endl;   
    }
}    
}
