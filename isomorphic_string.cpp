#include "isomorphic_string.h"

using std::string;

template <size_t _>
void init(int (&set)[_]) {
    for (int &i: set) {
        i = -1;
    }
}

bool isomorphic_string::Solution::isIsomorphic(string s, string t) {
    if (t.size() != s.size()) {
        return false;
    }
    int mapping[128];
    int reverse[128];
    init(mapping);
    init(reverse);
    for (int i = 0; i < s.size(); i++) {
        auto sourceChar = s[i];
        auto targetChar = t[i];
        if (mapping[sourceChar] == -1 && reverse[targetChar] == -1) {
            mapping[sourceChar] = targetChar;
            reverse[targetChar] = sourceChar;
        } else if (mapping[sourceChar] != targetChar) {
            return false;
        }
    }
    return true;
}