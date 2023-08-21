#include "substring_with_concat.h"

#include <unordered_map>


using std::vector;
using std::string;
using std::string_view;
using std::unordered_map;


unordered_map<string_view, int> create(vector<string> &words) {
    auto result = unordered_map<string_view, int>();
    for (const auto &value: words) {
        auto search = result.find(value);
        if (search == result.cend()) {
            result[value] = 1;
        } else {
            search->second++;
        }
    }
    return result;
}

void reset(unordered_map<string_view, int> &copy, const unordered_map<string_view, int> &orig) {
    for (const auto &value: orig) {
        copy[value.first] = value.second;
    }
}

vector<int> substring_with_concat::Solution::findSubstring(string s, vector<string> &words) {
    auto result = vector<int>();
    if (words.empty()) {
        return result;
    }
    auto len = words[0].length();
    auto substrLength = len * words.size();
    auto orig = create(words);
    auto copy = unordered_map(orig);
    auto view = string_view(s);
    for (int i = 0; i + substrLength <= s.size(); i++) {
        bool found = true;
        for (int j = 0; j < words.size(); j++) {
            auto start = i + j * len;
            auto sub = view.substr(start, len);
            auto search = copy.find(sub);
            if (search == copy.cend() || search->second == 0) {
                found = false;
                break;
            }
            search->second--;
        }
        if (found) {
            result.push_back(i);
        }
        reset(copy, orig);
    }
    return result;
}
