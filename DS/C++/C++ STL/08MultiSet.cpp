// MultiSet in STL
// Author: REET

/*
Similar to set but has the ability to
store duplicates.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(2); // {1, 2}
    ms.insert(2); // {1, 2, 2}
    ms.insert(4); // {1, 2, 2, 4}
    ms.insert(5); // {1, 2, 2, 4, 5}
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    ms.erase(2);
    // It will erase all the 2
    cout << "After Erasing:" << endl;
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    ms.insert(2); // {1, 2, 4, 5}
    ms.insert(2); // {1, 2, 2, 4, 5}
    ms.insert(2); // {1, 2, 2, 2, 4, 5}
    ms.insert(2); // {1, 2, 2, 2, 4, 5}
    int cnt = ms.count(2);
    cout << "The count of element 2 is: " << cnt << endl;
    ms.erase(ms.find(2));
    // It'll delete only the first 2
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
1 2 2 4 5 
After Erasing:
1 4 5 
The count of element 2 is: 4
1 2 2 2 4 5 
*/