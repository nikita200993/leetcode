//
// Created by nikita on 26.07.23.
//

#include "RandomizedSet.h"

#include <unordered_set>
#include <cstdlib>

namespace randomized_set {
    bool RandomizedSet::insert(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        vec.push_back(val);
        map.
    }

    bool RandomizedSet::remove(int val) {
        return this->set.erase(val);
    }

    int RandomizedSet::getRandom() {
        auto index = std::rand() % set.size();
        set.e
    }

} // randomized_set