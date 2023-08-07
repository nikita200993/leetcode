#include "int_to_roman.h"

std::string int_to_roman::Solution::intToRoman(int num) {
    std::string result;
    int ms = num / 1000;
    for (int i = 0; i < ms; i++) {
        result.push_back('M');
    }
    int other = num % 1000;
    if (other >= 900) {
        result.append("CM");
        other -= 900;
    } else if (other >= 500) {
        result.push_back('D');
        other -= 500;
    }
    if (other >= 400) {
        result.append("CD");
        other -= 400;
    }
    int c = other / 100;
    other = other % 100;
    for (int i = 0; i < c; i++) {
        result.push_back('C');
    }
    if (other >= 90) {
        result.append("XC");
        other -= 90;
    } else if (other >= 50) {
        result.push_back('L');
        other -= 50;
    }
    if (other >= 40) {
        result.append("XL");
        other -= 40;
    }
    int x = other / 10;
    other = other % 10;
    for (int i = 0; i < x; i++) {
        result.push_back('X');
    }
    if (other == 9) {
        result.append("IX");
        other -= 9;
    } else if (other >= 5) {
        result.push_back('V');
        other -= 5;
    }
    if (other == 4) {
        result.append("IV");
        other -= 4;
    }
    for (int i = 0; i < other; i++) {
        result.push_back('I');
    }
    return result;
}

