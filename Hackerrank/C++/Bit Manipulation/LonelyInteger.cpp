#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

void solve(const std::vector<unsigned int> &a) {
        unsigned int res = std::accumulate(a.begin(), a.end(), 0, [](int k, int i) { return k = k ^ i; });
        std::cout << res << std::endl;

}

int main() {
        unsigned int length;
        std::cin >> length;

        std::vector<unsigned int> nums = {};

        for (int i = 0; i < length; ++i) {
                int tmp;
                std::cin >> tmp;
                nums.push_back(tmp);
        }

        solve(nums);
        return 0;
}

