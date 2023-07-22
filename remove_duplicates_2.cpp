//
// Created by nikita on 20.07.23.
//

#include "remove_duplicates_2.h"
#include <vector>

using std::vector;

int Solution::removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int lastUniqueElement = 0;
    int repeat = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != nums[lastUniqueElement]) {
            repeat = 1;
            nums[++lastUniqueElement] = nums[i];
        } else if (repeat == 1) {
            repeat++;
            nums[++lastUniqueElement] = nums[i];
        } else {
            repeat++;
        }
    }
    nums.erase(nums.cbegin() + lastUniqueElement + 1, nums.cend());
    return nums.size();
}

