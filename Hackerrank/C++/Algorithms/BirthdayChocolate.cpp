#include <bits/stdc++.h>

int solve(const int &n, const std::vector<int> &s, const int &d, const int &m) {
  
    int matches = 0;
    
    // start at each peice
    for (int i = 0; i < s.size(); i++) {
        
        int j = i + 1;
        int peices = 1;
        int sum = s[i];
        
        // accumulate peices
        while (peices < m && sum < d && j < s.size()) {
            sum += s[j];
            peices++;
            j++;
        }
        
        if (peices == m && sum == d) {
            matches++;
        }
        
    }

    return matches;
}

int main() {
    
    int n;
    std::cin >> n;
    
    // get rows
    std::vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       std::cin >> s[s_i];
    }
    
    // get birthday
    int d, m;
    std::cin >> d >> m;
    
    // calc answer
    int result = solve(n, s, d, m);
    std::cout << result << std::endl;
    
    return 0;
    
}
