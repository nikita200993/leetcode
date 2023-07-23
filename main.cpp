#include <iostream>
#include <vector>
#include "rotate_array.h"

using std::vector;

using rotate_array::Solution;

template <typename T>
void print(const vector<T> &vec);

int main() {
    auto left = vector<int>({1, 2, 3, 4, 5});
    Solution().rotate(left, 4);
    print(left);
    return 0;
}

template <typename T>
void print(const vector<T> &vec) {
    for (auto &element : vec) {
        std::cout << element << std::endl;
    }
}
