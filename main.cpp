#include <iostream>
#include <vector>
#include "majority_element.h"

using std::vector;


int main() {
    auto left = vector<int>({1, 2, 2, 3, 2});
    std::cout << Solution().majorityElement(left) << std::endl;
    return 0;
}
