#include <iostream>
#include <algorithm>
#include <vector>

struct Tree {
    int _position;
    std::vector<int> _dropping_positions;
public:
    Tree(const int &, const std::vector<int> &);
    const int quantity_in_range(const int &, const int &);
};

Tree::Tree(const int &position, const std::vector<int> &deltas) {
    _position = position;
    for (const int delta : deltas) {
        _dropping_positions.push_back(_position + delta);
    }
}

const int Tree::quantity_in_range(const int &start, const int &end) {
    int count = 0;
    
    for (const int pos : _dropping_positions) {
        if (start <= pos && pos <= end) {
            count++;
        }
    }
    
    return count;
}

int main() {
    
    int start, end, a, b, m, n;
    
    std::cin >> start >> end; // get start/end
    std::cin >> a >> b; // get tree positions
    std::cin >> m >> n; // get number off apples & oranges
    
    // populate apple positions
    std::vector<int> apples(m);
    for(int i = 0; i < m; i++){
       std::cin >> apples[i];
    }
       
    // populate oranges positions
    std::vector<int> oranges(n);
    for(int j = 0; j < n; j++){
       std::cin >> oranges[j];
    }
    
    // instantiate trees
    Tree apple_tree(a, apples);
    Tree orange_tree(b, oranges);
    
    // get droppings in range
    std::cout << apple_tree.quantity_in_range(start, end) << std::endl;
    std::cout << orange_tree.quantity_in_range(start, end) << std::endl;
    
    return 0;
    
}
