// Map in STL
// Author: REET

/*
Stores key value pair.
Stores in the sorted fashion a/c to key.
erase(), swap(), size(), empty() same as
vectors.
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp0;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, string> mp2;
    mp0[1] = 2;
    mp0.emplace(3, 1);
    mp0.insert({2, 4});
    mp0.insert({4, 9});
    // Map is now: {1, 2}, {2, 4}, {3, 1}, {4, 9}
    cout << "Value of key 4 is: " << mp0[4] << endl;
    // Prints value associated with key 4
    // auto it = mp0.find(4);
    // cout << *(it).second << endl;
    // Not working don't know the reason for that
    for (auto i : mp0)
    {
        cout << "{" << i.first << "," << i.second << "} ";
    }
    cout << endl;

    mp2[{2, 4}] = "REET";
    for (auto i : mp2)
    {
        cout << "mp2[{" << i.first.first << ", " << i.first.second << "}]= " << i.second << endl;
    }

    // auto it = mp0.lower_bound(key);
    // auto it = mp0.upper_bound(key);
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Value of key 4 is: 9
{1,2} {2,4} {3,1} {4,9} 
mp2[{2, 4}]= REET
*/