#include <iostream>
#include <vector>
#include "common_prefix.h"

using std::vector;

template<typename Type>
class TD;


int main() {
    auto vec = vector<std::string>();
    vec.emplace_back("flower");
    vec.emplace_back("flow");
    vec.emplace_back("flight");
    auto result = common_prefix::Solution().longestCommonPrefix(vec);
    std::cout << result << std::endl;
}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



