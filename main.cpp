#include <iostream>
#include "reverse_words_string.h"

using std::vector;

template<typename Type>
class TD;


int main() {
    auto str = std::string(" asdasd df f");
    auto result = reverse_words_string::Solution().reverseWords(str);
    std::cout << result << std::endl;
}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



