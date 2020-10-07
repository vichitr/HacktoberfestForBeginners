// DeQueue in STL
// Author: REET

/*
Similar to vector.
All methods of vector are applicable such
as begin, end, rbegin, rend, clear, 
insert, size, swap...
*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.emplace_back(9);  // {9}
    dq.push_back(1);     // {9, 1}
    dq.push_front(3);    // {3, 9, 1}
    dq.emplace_front(7); // {7, 3, 9, 1}
    cout << "Element at front of deque: " << dq.front() << endl;
    cout << "Element at back of deque: " << dq.back() << endl;

    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Element at front of deque: 7
Element at back of deque: 1
*/