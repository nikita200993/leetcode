#include <iostream>
#include <vector>
#include "remove_element.h"

using std::vector;


int main() {
    auto left = vector<int>({2, 3, 3, 2, 3, 1, 3, 1, 3, 3, 1});
    Solution().removeElement(left, 3);
    std::cout << "Iterating..." << std::endl;
    for (auto &element : left) {
        std::cout << element << std::endl;
    }
    return 0;
}
