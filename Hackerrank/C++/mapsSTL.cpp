#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

//Problem https://www.hackerrank.com/challenges/cpp-maps/problem

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int iQueries, iType;
    long long iData;
    string sName;
    unordered_map<string, long long> mStudents;
    cin >> iQueries;
    while (iQueries--){
        cin >> iType;
        switch (iType){
            case 1:
                cin >> sName >> iData;
                mStudents[sName] += iData;
                break;
            case 2:
                cin >> sName;
                mStudents[sName] = 0;
                break;
            case 3:
                cin >> sName;
                cout << mStudents[sName] << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}