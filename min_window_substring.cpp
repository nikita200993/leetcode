#include "min_window_substring.h"
#include <unordered_map>

using std::string;
using std::unordered_map;

unordered_map<char, int> create(const string &t) {
    unordered_map<char, int> result;
    for (auto letter: t) {
        auto search = result.find(letter);
        if (search == result.cend()) {
            result[letter] = 1;
        } else {
            search->second++;
        }
    }
    return result;
}

int match(const string &str, unordered_map<char, int> &map) {
    auto matchesRemained = map.size();
    int len = 0;
    for (auto value: str) {
        auto search = map.find(value);
        if (search != map.cend()) {
            if ((search->second--) == 1) {
                matchesRemained--;
            }
        }
        len++;
        if (matchesRemained == 0) {
            return len;
        }
    }
    return -1;
}

struct position {
    int start;
    int length;
};

position shrink_match_zone(unordered_map<char, int> &map, position pos, const string &s) {
    position result = pos;
    for (int i = pos.start, j = pos.start + pos.length - 1; i < j;) {
        auto searchStart = map.find(s[i]);
        auto searchEnd = map.find(s[j]);
        bool changed = false;
        if (searchEnd != map.cend() && searchEnd->second < 0) {
            changed = true;
            searchEnd->second++;
            j--;
        }
        if (searchEnd == map.cend()) {
            changed = true;
            j--;
        }
        if (searchStart != map.cend() && searchStart->second < 0) {
            changed = true;
            searchStart->second++;
            i++;
        }
        if (searchStart == map.cend()) {
            changed = true;
            i++;
        }
        if (!changed) {
            break;
        }
        result = {i, j - i + 1};
    }
    return result;
}


string min_window_substring::Solution::minWindow(string s, string t) {
    if (t.empty()) {
        return {};
    }
    auto map = create(t);
    int len = match(s, map);
    if (len == -1) {
        return {};
    }
    auto pos = shrink_match_zone(map, {0, len}, s);
    int matchesRemained = 0;
    for (int i = pos.start + 1; i + pos.length <= s.size(); i++) {
        auto search = map.find(s[i - 1]);
        if (search != map.cend()) {
            if ((search->second++) == 0) {
                matchesRemained++;
            }
        }
        search = map.find(s[i + pos.length - 1]);
        if (search != map.cend()) {
            if ((search->second--) == 1) {
                matchesRemained--;
            }
        }
        if (matchesRemained == 0) {
            auto newPos = shrink_match_zone(map, {i, pos.length}, s);
            i = newPos.start;
            if (newPos.length < pos.length) {
                pos = newPos;
            }
        }
    }
    return s.substr(pos.start, pos.length);
}
