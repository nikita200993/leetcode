#include "set_matrix_zero.h"

using std::vector;

void set_matrix_zero::Solution::setZeroes(std::vector<std::vector<int>> &matrix) {
    auto killedRows = vector<bool>(matrix.size(), false);
    auto killedCols = vector<bool>(matrix[0].size(), false);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                killedRows[i] = true;
                killedCols[j] = true;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (killedRows[i] || killedCols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
