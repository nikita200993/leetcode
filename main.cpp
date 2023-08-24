#include <iostream>

#include "word_pattern.h"

using std::vector;
using std::string;

template<typename Type>
class TD;

template<typename T>
void print(const vector<T> &vec);

template<typename T>
void print(const vector<vector<T>> &vec);


int main() {
    auto pattern = string("abab");
    auto s = string("chicken beef chicken beef");
    auto result = word_pattern::Solution().wordPattern(pattern, s);
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
