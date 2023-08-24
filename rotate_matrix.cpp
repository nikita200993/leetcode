#include "rotate_matrix.h"

using std::vector;

void rotate_matrix::Solution::rotate(std::vector<std::vector<int>> &matrix) {
    int length = matrix.size();
    int centerX = matrix.size() / 2 + matrix.size() % 2;
    int centerY = matrix.size() / 2;
    for (int i = 0; i < centerY; i++) {
        for (int j = 0; j < centerX; j++) {
            int secondI = j;
            int secondJ = length - i - 1;
            int thirdI = length - i - 1;
            int thirdJ = length - j - 1;
            int fourthI = length - 1 - secondI;
            int fourthJ = length - 1 - secondJ;
            std::swap(matrix[i][j], matrix[secondI][secondJ]);
            std::swap(matrix[i][j], matrix[thirdI][thirdJ]);
            std::swap(matrix[i][j], matrix[fourthI][fourthJ]);
        }
    }
}