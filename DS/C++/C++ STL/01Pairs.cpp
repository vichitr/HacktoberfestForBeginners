// Pairs in STL
// Author: REET

#include <iostream>
using namespace std;

/*
Standard Template Library(STL).
STL basically provides four components
which ease the CP journey.
The components are: algorithms,containers
*/

int main()
{
    // Single Pair
    pair<int, int> p = {1, 3};
    cout << "The first element of pair is: " << p.first << endl;
    cout << "The second element of pair is: " << p.second << endl;

    // Pair within pair
    pair<int, pair<int, int>> pp = {1, {4, 2}};
    cout << "The first element of the first element of pair is: " << pp.first << endl;
    cout << "The first element of the second element of pair is: " << pp.second.first << endl;
    cout << "The second element of the second element of pair is: " << pp.second.second << endl;

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << "First element of the pair at Index [0]: " <<arr[0].first << endl;
    cout << "Second element of the pair at Index [0]: " <<arr[0].second << endl;
    cout << "First element of the pair at Index [1]: " <<arr[1].first << endl;
    cout << "Second element of the pair at Index [1]: " <<arr[1].second << endl;
    cout << "First element of the pair at Index [2]: " <<arr[2].first << endl;
    cout << "Second element of the pair at Index [2]: " <<arr[2].second << endl;

    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
The first element of pair is: 1
The second element of pair is: 3
The first element of the first element of pair is: 1
The first element of the second element of pair is: 4
The second element of the second element of pair is: 2
First element of the pair at Index [0]: 1
Second element of the pair at Index [0]: 2
First element of the pair at Index [1]: 2
Second element of the pair at Index [1]: 5
First element of the pair at Index [2]: 5
Second element of the pair at Index [2]: 1
*/