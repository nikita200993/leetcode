#include "sudoku.h"

template <size_t rows, size_t cols>
bool addDigit(char digit, size_t row, bool (&set)[rows][cols]) {
    if (set[row][digit - '1']) {
        return false;
    } else {
        set[row][digit - '1'] = true;
        return true;
    }
}

template <size_t rows, size_t cols>
void fillSet(bool (&set)[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j++) {
            set[i][j] = false;
        }
    }
}

bool sudoku::Solution::isValidSudoku(std::vector<std::vector<char>> &board) {
    bool setRow[9][9];
    bool setCols[9][9];
    bool setSquares[9][9];
    fillSet(setRow);
    fillSet(setCols);
    fillSet(setSquares);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            auto numRow = i * 3;
            auto numCol = j * 3;
            for (size_t i_inner = 0; i_inner < 3; i_inner++) {
                for (size_t j_inner = 0; j_inner < 3; j_inner++) {
                    auto rowIndex = numRow + i_inner;
                    auto colIndex = numCol + j_inner;
                    auto squareIndex = i * 3 + j;
                    auto letter = board[rowIndex][colIndex];
                    bool valid = true;
                    if (letter != '.') {
                        valid = addDigit(letter, rowIndex, setRow);
                        valid &= addDigit(letter, colIndex, setCols);
                        valid &= addDigit(letter, squareIndex, setSquares);
                    }
                    if (!valid) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
