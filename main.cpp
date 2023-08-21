#include <iostream>

#include "min_window_substring.h"

using std::vector;
using std::string;

template<typename Type>
class TD;

template<typename T>
void print(const vector<T> &vec);

template<typename T>
void print(const vector<vector<T>> &vec);


int main() {
    auto t = string("cae");
    auto s = string("cfabeca");
    auto result = min_window_substring::Solution().minWindow(s, t);
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
