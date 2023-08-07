#include "common_prefix.h"


std::string common_prefix::Solution::longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty()) {
        return "";
    }
    auto prefix = strs[0];
    for (const auto &value: strs) {
        int counter = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (i + 1 > value.size() || prefix[i] != value[i]) {
                break;
            }
            counter++;
        }
        auto start = prefix.cbegin() + counter;
        prefix.erase(start, prefix.cend());
    }
    return prefix;
}
