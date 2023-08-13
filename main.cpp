#include <iostream>
#include "zig_zag.h"

using std::vector;

template<typename Type>
class TD;


int main() {
    auto str = std::string("PAYPALISHIRING");
    auto result = zig_zag::Solution().convert(str, 4);
    std::cout << result << std::endl;
}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



