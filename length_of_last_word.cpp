#include "length_of_last_word.h"

int length_of_last_word::Solution::lengthOfLastWord(std::string s) {
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[s.size() - 1 - i] != ' ') {
            break;
        } else {
            counter++;
        }
    }
    if (counter == s.size()) {
        return 0;
    }
    int search_length = s.size() - counter;
    int idx = s.find_last_of(' ', search_length - 1);
    if (idx < 0) {
        return search_length;
    }
    return search_length - 1 - idx;
}