// Priority Queue in STL
// Author: REET

/*
Uses the property of both stack and queue
size(), swap(), empty() functions are
same as others.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;

    // Minimum Priority Queue
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);     // {5}
    pq1.push(2);     // {2, 5}
    pq1.push(8);     // {2, 5, 8}
    pq1.emplace(10); // {2, 5, 8, 10}

    cout << pq1.top() << endl;
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
10
8
2
*/