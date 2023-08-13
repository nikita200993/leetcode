#include "two_sum_2_sorted.h"

using std::vector;

vector<int> two_sum_2_sorted::Solution::twoSum(std::vector<int> &numbers, int target) {
    for (auto start = numbers.cbegin(), end = numbers.cend() - 1; start < end;) {
        int currentSum = (*start) + (*end);
        if (currentSum < target) {
            start++;
        } else if (currentSum == target) {
            int startIndex = start - numbers.cbegin();
            int endIndex = end - numbers.cbegin();
            return {startIndex + 1, endIndex + 1};
        } else {
            end--;
        }
    }
    return {};
}