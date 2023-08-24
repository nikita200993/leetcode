#include "spiral.h"

using std::vector;

vector<int> spiral::Solution::spiralOrder(vector<vector<int>> &matrix) {
    int sizeY = matrix.size();
    int sizeX = matrix[0].size();
    int total = sizeX * sizeY;
    int centerY = sizeY / 2 + sizeY % 2 - 1;
    int centerX = sizeX / 2 - 1;
    int i = 0;
    int j = 0;
    int count = 0;
    auto result = vector<int>();
    result.reserve(total);
    while (count < total) {
        count++;
        result.push_back(matrix[i][j]);
        if (i <= centerY && j <= centerX) {
            int order = std::min(i, j) + 1;
            if (i == order - 1 || i == order) {
                j++;
            } else {
                i--;
            }
        } else if (i <= centerY && j > centerX) {
            int order = std::min(i, sizeX - j - 1) + 1;
            if (sizeX - j == order) {
                i++;
            } else {
                j++;
            }
        } else if (i > centerY && j <= centerX) {
            int order = std::min(sizeY - i - 1, j) + 1;
            if (j == order - 1) {
                i--;
            } else {
                j--;
            }
        } else {
            int order = std::min(sizeY - i - 1, sizeX - j - 1) + 1;
            if (sizeY - i == order) {
                j--;
            } else {
                i++;
            }
        }
    }
    return result;
}
