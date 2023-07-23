#include "rotate_array.h"

using std::vector;

void _rotate(std::vector<int> &nums, int k, int size);
void _rotate2(std::vector<int> &nums, int k);

void rotate_array::Solution::rotate(std::vector<int> &nums, int k) {
    _rotate2(nums, k);
}

void _rotate(std::vector<int> &nums, int k, int size) {
    if (size == 0 || size == 1) {
        return;
    }
    int normalized_k = k % size;
    if (normalized_k == 0) {
        return;
    }
    for (int i = 0; i < size - normalized_k; i++) {
        int i_normalized = i % normalized_k;
        int tmp = nums[i + normalized_k];
        nums[i + normalized_k] = nums[i_normalized];
        nums[i_normalized] = tmp;
    }
    _rotate(nums, normalized_k - size % normalized_k, normalized_k);
}

void _rotate2(std::vector<int> &nums, int k) {
    int size = nums.size();
    int normalized_k = k % size;
    while (size > 1 && normalized_k > 0) {
        for (int i = 0; i < size - normalized_k; i++) {
            int i_normalized = i % normalized_k;
            int tmp = nums[i + normalized_k];
            nums[i + normalized_k] = nums[i_normalized];
            nums[i_normalized] = tmp;
        }
        int new_size = normalized_k;
        normalized_k = (normalized_k - size % normalized_k) % new_size;
        size = new_size;
    }
}
