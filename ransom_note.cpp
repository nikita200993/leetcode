#include "ransom_note.h"

using std::string;

void letterSet(int (&set)[26]) {
    for (int i = 0; i < 26; i++) {
        set[i] = 0;
    }
}

bool ransom_note::Solution::canConstruct(string ransomNote, string magazine) {
    int needed[26];
    int actual[26];
    letterSet(needed);
    letterSet(actual);
    for (auto value: ransomNote) {
        needed[value - 'a']++;
    }
    for (auto value: magazine) {
        actual[value - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (actual[i] < needed[i]) {
            return false;
        }
    }
    return true;
}
