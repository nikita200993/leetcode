#ifndef LEETCODE_RANDOMIZEDSET_H
#define LEETCODE_RANDOMIZEDSET_H

#include <unordered_map>
#include <vector>

namespace randomized_set {

    class RandomizedSet {
    public:
        RandomizedSet() {};
        bool insert(int val);
        bool remove(int val);
        int getRandom();
    private:
        std::unordered_map<int, int> map;
        std::vector<int> vec;
    };
} // randomized_set

#endif //LEETCODE_RANDOMIZEDSET_H
