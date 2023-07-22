//
// Created by nikita on 18.07.23.
//

#include "merge_sorted_arrays.h"
#include "vector"

using std::vector;

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int first = m - 1;
    int second = n - 1;
    for (long i = n + m - 1; i >= 0; i--) {
        if (second < 0) {
            return;
        } else if (first < 0 || nums2[second] > nums1[first]) {
            nums1[i] = nums2[second--];
        } else {
            nums1[i] = nums1[first--];
        }
    }
}


