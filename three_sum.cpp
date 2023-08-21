#include "three_sum.h"

using std::vector;

auto twoSum(int start,
            const vector<int> &values) {
    vector<vector<int>> result;
    int first = start;
    int last = values.size() - 1;
    int target = -values[start - 1];
    while (first < last) {
        if (values[first] > target) {
            return result;
        }
        if (first != start && values[first] == values[first - 1]) {
            first++;
            continue;
        }
        int sum = values[first] + values[last];
        if (sum > target) {
            last--;
        } else if (sum < target) {
            first++;
        } else {
            result.push_back({values[start - 1], values[first], values[last]});
            first++;
        }
    }
    return result;
}

vector<vector<int>> three_sum::Solution::threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0) {
            return result;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        auto search = twoSum(i + 1, nums);
        result.insert(result.end(), std::make_move_iterator(search.begin()), std::make_move_iterator(search.end()));
    }
    return result;
}
