#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>

int round_grade(const int &grade) {
    int diff = grade % 5;
    if (diff >= 3 && grade >= 38) {
        return grade + (5 - diff);
    }
    return grade;
}

std::vector<int> solve(const std::vector<int> &grades) {
    std::vector<int> result;
    result.reserve(grades.size());
    // map new grades
    std::transform(grades.begin(), grades.end(), std::back_inserter(result), round_grade);
    
    return result;
}

int main() {
    
    int n;
    std::cin >> n;
    
    // get grades
    std::vector<int> grades(n);
    for(int i = 0; i < n; i++) {
       std::cin >> grades[i];
    }
    
    // get results
    std::vector<int> results = solve(grades);
    for (const int result : results) {
        std::cout << result << std::endl;
    }
        
    return 0;
    
}
