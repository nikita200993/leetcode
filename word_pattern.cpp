#include "word_pattern.h"

#include "string_view"
#include "unordered_set"

using std::string;
using std::string_view;
using std::unordered_set;

bool word_pattern::Solution::wordPattern(string pattern, string s) {
    string_view set[128];
    unordered_set<string_view> unique;
    int size = 0;
    int offset = 0;
    int totalLength = 0;
    for (int i = 0; i < pattern.size(); i++) {
        auto letter = pattern[i];
        int length = 0;
        for (int j = offset; s[j] != ' ' && j < s.size(); j++) {
            length++;
        }
        if (length == 0) {
            return false;
        }
        totalLength += length;
        auto view = string_view(s).substr(offset, length);
        offset += (length + 1);
        unique.insert(view);
        if (set[letter].empty()) {
            size++;
            set[letter] = view;
        } else if (set[letter] != view) {
            return false;
        }
        if (size != unique.size()) {
            return false;
        }
    }
    if (offset < s.size()) {
        return false;
    }
    return true;
}