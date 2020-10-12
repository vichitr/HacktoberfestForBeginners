#include <iostream>
#include <numeric>

#define k_32bit_1 0xffffffff

int main() {
    uint32_t count;
    std::cin >> count;
    
    for (int i = count; i; --i) {
        uint32_t tmp;
        std::cin >> tmp;
        std::cout << (tmp ^ k_32bit_1) << std::endl;
    }
    
    return 0;
}

