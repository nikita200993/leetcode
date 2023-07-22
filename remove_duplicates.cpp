//
// Created by nikita on 18.07.23.
//

#include "remove_duplicates.h"
#include <vector>

using std::vector;

int remove_duplicates::Solution::removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int lastUniqueElement = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != nums[lastUniqueElement]) {
            nums[++lastUniqueElement ] = nums[i];
        }
    }
    nums.erase(nums.cbegin() + lastUniqueElement + 1, nums.cend());
    return nums.size();
}
