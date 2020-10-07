// Author: REET
/*
These are the extra functionality that
STL provides to us.
-----------------------------------------
sort(it1, it2);
Sorts the element from the address
iterator(it1) to the address it2 
excluding it2.
Sorts in ascending order.
If you need to sort in descending order.
sort(a, a+n, greater<int>);
pair<int, int> a[] = {{1,2},{2,1},{4,1}};
If you want to sort elements as per your 
wish, define a comparator.
Let's wish I want to sort it according
to the second value of the pair.
{{4,1},{2,1},{1,2}}
sort(a, a+n, comp);
bool comp(pair<int, int>p2, 
pair<int, int>p2) {
    if(p1.second < p2.second)
    return true;
    else if(p1.second == p2.second) {
        if(p1.first > p2.first)
        return true;
    }
    return false;
}
-----------------------------------------
int num = 7; //111(Binary Representation)
int cnt = __builtin_popcount();
long long num = 126876128731873;
int cnt = __builtin_popcountll();
-----------------------------------------
string s = "123";
do {
    cout << s << endl;
} while(next_permutation(s.begin(), 
s.end()));
// 123
// 132
// 213
// 231
// 312
// 321
-----------------------------------------
int maxi = *max_element(a,a+n);
Returns the maximum element present.
-----------------------------------------
*/

//
// Author: REET

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "123";
    cout << "next_permutation" << endl;
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(),
                              s.end()));
    cout << "__builtin_popcount" << endl;
    int num = 7; //111
    int cnt1 = __builtin_popcount(num);
    cout << cnt1 << endl;
    long long num2 = 126876128731873;
    int cnt2 = __builtin_popcountll(num2);
    cout << cnt2 << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
next_permutation
123
132
213
231
312
321
__builtin_popcount
3
23
*/