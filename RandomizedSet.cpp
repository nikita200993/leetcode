#include "RandomizedSet.h"

#include <unordered_map>
#include <vector>
#include <random>

namespace randomized_set {
    bool RandomizedSet::insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        vec.push_back(val);
        map[val] = vec.size() - 1;
        return true;
    }

    bool RandomizedSet::remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        int pos = map[val];
        if (pos != (vec.size() - 1)) {
            std::swap(vec[pos], vec[vec.size() - 1]);
            map[vec[pos]] = pos;
        }
        vec.pop_back();
        map.erase(val);
        return true;
    }

    int RandomizedSet::getRandom() {
        auto index = dev() % vec.size();
        return vec[index];
    }

} // randomized_set