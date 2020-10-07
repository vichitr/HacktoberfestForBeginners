// List in STL
// Author: REET

#include <iostream>
#include <list>
using namespace std;

/*
Useful when we need to pop and push 
element at the front.
Similar to vector but we don't get any
method to directly push at the front in
vector.
All methods of vector are applicable such
as begin, end, rbegin, rend, clear, 
insert, size, swap...
Prefer Vector over list as it works 
better than list when in complexities.
*/

int main()
{
    list<int> ls;
    ls.push_back(2);      // {2}
    ls.emplace_back(4);   // {2, 4}
    ls.push_front(6);     // {6, 2, 4}
    ls.emplace_front(23); // {23, 6, 2, 4}
    ls.pop_back();        // {23, 6, 2}
    ls.pop_front();       // {6, 2}
    for (auto it : ls)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
6 2
*/