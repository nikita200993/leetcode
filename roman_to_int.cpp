#include "roman_to_int.h"

int getInt(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}

int roman_to_int::Solution::romanToInt(std::string s) {
    int sum = 0;
    int last = getInt(s[0]);
    for (auto letter: s) {
        int number = getInt(letter);
        if (number <= last) {
            sum += number;
        } else {
            sum += number;
            sum -= 2 * last;
        }
        last = number;
    }
    return sum;
}

