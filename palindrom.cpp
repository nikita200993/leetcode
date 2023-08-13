#include "palindrom.h"

bool palindrom::Solution::isPalindrome(std::string s) {
    for (auto start = s.cbegin(), end = s.cend(); start < end;) {
        if (!std::isalnum(*start)) {
            start++;
        } else if (!std::isalnum(*end)) {
            end--;
        } else if (std::tolower(*start) != std::tolower(*end)) {
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}