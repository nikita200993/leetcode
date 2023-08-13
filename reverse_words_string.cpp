#include "reverse_words_string.h"
#include <iostream>

std::string reverse_words_string::Solution::reverseWords(std::string s) {
    std::string result;
    std::string buffer;
    bool afterWord = false;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (afterWord && s[i] == ' ' && i != 0) {
            for (int i = buffer.size() - 1; i >= 0; i--) {
                result.push_back(buffer[i]);
            }
            buffer.clear();
            result.push_back(s[i]);
            afterWord = false;
        } else if (s[i] != ' ') {
            buffer.push_back(s[i]);
            afterWord = true;
        }
    }
    for (int i = buffer.size() - 1; i >= 0; i--) {
        result.push_back(buffer[i]);
    }
    std::cout << result << std::endl;
    if (!result.empty() && result[result.size() - 1] == ' ') {
        result.erase(result.cend());
    }
    return result;
}
