// Queue in STL
// Author: REET

/*
Based on FIFO(First in First Out) 
principle.
size(), swap(), empty() same as stack
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);     // {1}
    q.push(2);     // {1, 2}
    q.emplace(4);  // {1, 2, 4}
    q.back() += 5; // {1, 2, 9}

    cout << "Element at the front is: " << q.front() << endl;
    q.pop(); // {2, 9}
    cout << "New element at the front is: " << q.front() << endl;
    cout << "Element at the back is: " << q.back() << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Element at the front is: 1
New element at the front is: 2
Element at the back is: 9
*/