// MultiMap in STL
// Author: REET

/*
Works in similar fashion as of map.
But has the ability to store multiple 
same key value pair.
If you want to store something like {1,3}
and {1,4} map allows that.
So there is no need to use multimap in
that case.
But only if you're required to store both
same key and value multiple times then
refer MultiMap.
Only mp0[key] can not be used here.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int, int> mp0;
    // Rest are same as map
    return 0;
}