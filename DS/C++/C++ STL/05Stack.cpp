// Stack in STL
// Author: REET

/*
Based on LIFO(Last in First Out) 
principle.
Doesn't allow to access element by index
as in case of a vector.
Only top most element can be accessed.
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);    // {1}
    st.push(20);    // {2, 1}
    st.push(30);    // {3, 2, 1}
    st.push(40);    // {4, 3, 2, 1}
    st.emplace(50); // {5, 4, 3, 2, 1}
    cout << "Element at top is: " << st.top() << endl;
    st.pop();
    cout << "New element at top is: " << st.top() << endl;
    cout << "Size of the stack is: " << st.size() << endl;
    st.empty();
    stack<int> st1, st2;
    st1.swap(st2);
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Element at top is: 50
New element at top is: 40
Size of the stack is: 4
*/