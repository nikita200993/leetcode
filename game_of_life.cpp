#include "game_of_life.h"

using std::vector;

int getVal(int i) {
    if (i == 1 || i == -3 || i == -4) {
        return 1;
    } else {
        return 0;
    }
}

void setCell(int i, int j, vector<vector<int>> &board) {
    int sum = 0;
    if (i > 0 && j > 0) {
        sum += getVal(board[i - 1][j - 1]);
    }
    if (i > 0) {
        sum += getVal(board[i - 1][j]);
    }
    if (j > 0) {
        sum += getVal(board[i][j - 1]);
    }
    if (i < board.size() - 1) {
        sum += getVal(board[i + 1][j]);
    }
    if (j < board[0].size() - 1) {
        sum += getVal(board[i][j + 1]);
    }
    if (i < board.size() - 1 && j < board[0].size() - 1) {
        sum += getVal(board[i + 1][j + 1]);
    }
    if (j < board[0].size() - 1 && i > 0) {
        sum += getVal(board[i - 1][j + 1]);
    }
    if (i < board.size() - 1 && j > 0) {
        sum += getVal(board[i + 1][j - 1]);
    }
    if (board[i][j] == 1 && sum < 2) {
        board[i][j] = -3;
    } else if (board[i][j] == 1 && sum < 4) {
        board[i][j] = -4;
    } else if (board[i][j] == 1) {
        board[i][j] = -3;
    } else if (board[i][j] == 0 && sum == 3) {
        board[i][j] = -2;
    } else {
        board[i][j] = -1;
    }
}

void game_of_life::Solution::gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            setCell(i, j, board);
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == -1 || board[i][j] == -3) {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
}
