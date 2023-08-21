#include "container_with_most_water.h"

int container_with_most_water::Solution::maxArea(std::vector<int> &height) {
    int minHeight = std::min(height[height.size() - 1], height[0]);
    int maxArea = minHeight * (height.size() - 1);
    for (int left = 0, right = height.size() - 1; left < right;) {
        if (height[left] <= minHeight) {
            left++;
        } else if (height[right] <= minHeight) {
            right--;
        } else {
            minHeight = std::min(height[left], height[right]);
            int area = minHeight * (right - left);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}
