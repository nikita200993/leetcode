#include "min_subarray_sub.h"

struct subInfo {
    int len;
    long sum;
};

auto findLength(int target, const std::vector<int> &nums) {
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum >= target) {
            return subInfo{i + 1, sum};
        }
    }
    return subInfo{-1, sum};
}

int min_subarray_sub::Solution::minSubArrayLen(int target, std::vector<int> &nums) {
    auto info = findLength(target, nums);
    if (info.len == -1) {
        return 0;
    }
    for (int i = 1; i < nums.size(); i++) {
        if (i + info.len > nums.size()) {
            info.len--;
            info.sum -= nums[i - 1];
            if (info.sum < target) {
                return info.len + 1;
            }
        } else {
            info.sum += nums[i + info.len - 1] - nums[i - 1];
            if (info.sum - nums[i + info.len - 1] >= target) {
                info.sum -= nums[i + info.len - 1];
                info.len--;
            }
        }
    }
    return info.len;
}