#include "trapping_rain_water.h"

int trapping_rain_water::Solution::trap(std::vector<int> &height) {
    int leftMax = height[0];
    int rightMax = height[height.size() - 1];
    int left = 1;
    int right = height.size() - 2;
    int sum = 0;
    while (left <= right) {
        if (height[left] >= leftMax) {
            leftMax = height[left];
            left++;
        } else if (height[right] >= rightMax) {
            rightMax = height[right];
            right--;
        } else if (leftMax <= rightMax) {
            sum += leftMax - height[left];
            left++;
        } else {
            sum += rightMax - height[right];
            right--;
        }

    }
    return sum;
}

