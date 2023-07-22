#include "majority_element.h"


int Solution::majorityElement(vector<int> &nums) {
    if (nums.empty()) {
        exit(1);
    }
    int lastIndex = 0;
    int counter = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != nums[lastIndex]) {
            counter--;
        } else {
            counter++;
        }
        if (counter == 0) {
            counter = 1;
            lastIndex = i;
        }
    }
    return nums[lastIndex];
}
