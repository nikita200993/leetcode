#include "longest_substring_without_repeat.h"

#include <unordered_set>

using std::string;
using std::unordered_set;

int longest_substring_without_repeat::Solution::lengthOfLongestSubstring(std::string s) {
    auto set = unordered_set<char>();
    int len = 0;
    for (auto value: s) {
        if (set.count(value) > 0) {
            break;
        } else {
            set.insert(value);
            len++;
        }
    }
    int maxLen = len;
    for (int i = 1; i < s.size(); i++) {
        if (i + maxLen > s.size()) {
            return maxLen;
        }
        set.erase(s[i - 1]);
        len--;
        for (int k = i + len; k < s.size() && set.count(s[k]) == 0; k++) {
            len++;
            set.insert(s[k]);
        }
        if (len > maxLen) {
            maxLen = len;
        }
    }
    return maxLen;
}