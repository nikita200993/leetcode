#include <iostream>
#include <vector>
#include "RandomizedSet.h"

using std::vector;


template <typename T>
void print(const vector<T> &vec);

int main() {
    auto set = randomized_set::RandomizedSet();
    set.insert(1);
    set.remove(2);
    set.insert(2);
    std::cout << set.getRandom() << std::endl;
    set.remove(1);
    set.insert(2);
    std::cout << set.getRandom() << std::endl;
    return 0;
}

template <typename T>
void print(const vector<T> &vec) {
    for (auto &element : vec) {
        std::cout << element << std::endl;
    }
}
