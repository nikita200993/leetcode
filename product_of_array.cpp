#include "product_of_array.h"
#include <vector>

namespace product_of_array {
    using std::vector;

    vector<int> Solution::productExceptSelf(vector<int> &nums) {
        auto result = vector<int>(nums.size());
        int productLeft = 1;
        int productRight = 1;
        for (int left = 0; left < nums.size(); left++) {
            int right = nums.size() - 1 - left;
            if (right > left) {
                result[left] = productLeft;
                result[right] = productRight;
            } else if (right == 0) {
                result[right] = productRight;
                result[left] = productLeft;
            } else if (left == right) {
                result[left] = productRight * productLeft;
            } else {
                result[right] = productRight * result[right];
                result[left] = productLeft * result[left];
            }
            productLeft *= nums[left];
            productRight *= nums[right];
        }
        return result;
    }
}
