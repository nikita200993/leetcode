#include <iostream>

#include "spiral.h"

using std::vector;
using std::string;

template<typename Type>
class TD;

template<typename T>
void print(const vector<T> &vec);

template<typename T>
void print(const vector<vector<T>> &vec);


int main() {
    vector<vector<int>> vec = {{2,5},{8,4},{0,-1}};
    auto result = spiral::Solution().spiralOrder(vec);
    print(result);
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
