#include "subsequence.h"


bool subsequence::Solution::isSubsequence(std::string s, std::string t) {
    int start = 0;
    for (auto toMatch: s) {
        if (start == t.size()) {
            return false;
        }
        while (start < t.size()) {
            start++;
            if (t[start - 1] == toMatch) {
                break;
            } else if (start == t.size()) {
                return false;
            }
        }
    }
    return true;
}