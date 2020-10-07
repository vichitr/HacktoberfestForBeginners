// Set in STL
// Author: REET

/*
Set stores elements in a sorted fashion.
Doesn't stores duplicates.
Function of insert in vector can also be
used, that only increases efficiency.
begin(), end(), rbegin(), rend(), size(),
empty() and swap() are same as those of
vectors.
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> st;
    st.insert(1);  // {1}
    st.insert(2);  // {1, 2}
    st.emplace(2); // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}
    for (auto i : st)
    {
        cout << i << " ";
    }
    auto it = st.find(3);
    cout << "\nFind Operation" << endl;
    cout << *it << endl;
    // Returns an iterator pointing at 3
    // auto it = st.find(6); != st.end()
    // != st.end() : ensures element is present
    // As no element present with value '6'
    // Points on memory address after the last element

    // set is now {1, 2, 3, 4}
    st.erase(3);
    // It takes logarithmic time
    cout << "After Erasing" << endl;
    for (auto i : st)
    {
        cout << i << " ";
    }

    int cnt = st.count(1);
    int cnt1 = st.count(6);
    // As set stores unique element the
    // value of cnt can only be 0 or 1
    // means absent or present
    cout << "\nElement 1 exists or not: " << cnt << endl;
    cout << "Element 6 exists or not: " << cnt1 << endl;

    // set is now {1, 2, 4}
    auto it2 = st.find(1);
    st.erase(it2);
    // It takes constant times
    for (auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;
    st.insert(1);
    st.insert(6);
    st.insert(8);
    st.insert(11);
    st.insert(14);
    // set is now {1, 2, 4, 6, 8, 11, 14}
    auto it4 = st.find(4);
    auto it5 = st.find(11);
    st.erase(it4, it5); // Exclude last one
    for(auto it: st) {
        cout << it << " ";
    }
    cout << endl;

    // lower_bound() & upper_bound() functions
    // work in the same way as in vector does
    auto it6 = st.lower_bound(2);

    auto it8 = st.upper_bound(4);
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
1 2 3 4 
Find Operation
3
After Erasing
1 2 4 
Element 1 exists or not: 1
Element 6 exists or not: 0
2 4 
1 2 11 14 
*/