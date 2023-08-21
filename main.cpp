#include <iostream>

#include "min_subarray_sub.h"

using std::vector;
using std::string;

template<typename Type>
class TD;

template<typename T>
void print(const vector<T> &vec);

template<typename T>
void print(const vector<vector<T>> &vec);


int main() {
    auto vec = vector({1,4,4});
    auto result = min_subarray_sub::Solution().minSubArrayLen(4, vec);
    std::cout << result << std::endl;
}

template<typename T>
void print(const vector<T> &vec) {
    bool first = true;
    std::cout << '[';
    for (auto &element: vec) {
        if (!first) {
            std::cout << ", ";
        }
        first = false;
        std::cout << element;
    }
    std::cout << ']';
}

template<typename T>
void print(const vector<vector<T>> &vec) {
    std::cout << '[';
    bool first = true;
    for (auto &element: vec) {
        if (!first) {
            std::cout << ", ";
        }
        first = false;
        print(element);
    }
    std::cout << ']';
}
