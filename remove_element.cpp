//
// Created by nikita on 18.07.23.
//

#include "remove_element.h"
#include <vector>

using std::vector;

int Solution::removeElement(vector<int> &nums, int val) {
    if (nums.empty()) {
        return 0;
    }
    int lastNonEqualElement = -1;
    int occur = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            occur++;
        } else if (lastNonEqualElement != i - 1) {
            nums[++lastNonEqualElement] = nums[i];
        } else {
            ++lastNonEqualElement;
        }
    }
    nums.erase(nums.cbegin() + lastNonEqualElement + 1, nums.cend());
    return nums.size();
}


