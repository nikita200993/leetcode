#include "zig_zag.h"

std::string zig_zag::Solution::convert(std::string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    std::string result;
    int periodLength = 2 * numRows - 2;
    for (int row = 0; row < numRows; row++) {
        int stepOne = periodLength - 2 * row;
        int stepTwo = periodLength - stepOne;
        int steps[] = {stepOne, stepTwo};
        int next = row;
        int counter = -1;
        while (next < s.size()) {
            result.push_back(s[next]);
            counter++;
            int step = steps[counter % 2];
            if (step == 0) {
                counter++;
                step = steps[counter % 2];
            }
            next += step;
        }
    }
    return result;
}
