#include <iostream>
#include "palindrom.h"

using std::vector;
using std::string;

template<typename Type>
class TD;

template<typename T>
void print(const vector<T> &vec);


int main() {
    auto str = string("");
    auto result = palindrom::Solution().isPalindrome();
    print(result);
}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



