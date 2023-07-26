#include "h_index.h"
#include <algorithm>

namespace h_index {
    // O(n * log(n)) time and O(1) additional memory
    int hIndexOne(std::vector<int> &citations) {
        auto freq = std::vector<int>(citations.size());
        for (auto value: citations) {
            if (value >= citations.size()) {
                freq[freq.size() - 1]++;
            } else if (value > 0) {
                freq[value - 1]++;
            }
        }
        long counter = 0;
        for (long i = citations.size() - 1; i >= 0; i--) {
            counter += freq[i];
            if (counter >= i + 1) {
                return i + 1;
            }
        }
    }

    // O(n) time and O(n) additional memory
    int hIndexTwo(std::vector<int> &citations) {
        std::sort(citations.begin(), citations.end());
        int hIndex = 0;
        for (long i = 0; i < citations.size(); i++) {
            if (citations[i] <= citations.size() - i; i++) {
                hIndex = citations[i];
            } else if (hIndex < citations.size() - i) {
                return citations.size() - i;
            } else {
                return hIndex;
            }
        }
    }
}

int h_index::Solution::hIndex(std::vector<int> &citations) {
    return hIndexTwo(citations);
}