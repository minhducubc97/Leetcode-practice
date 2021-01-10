// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes
// of the grid. The '.' character indicates empty cells.

// Example 1:
// Input: board =
// [["5","3",".",".","7",".",".",".","."],
// ["6",".",".","1","9","5",".",".","."],
// [".","9","8",".",".",".",".","6","."],
// ["8",".",".",".","6",".",".",".","3"],
// ["4",".",".","8",".","3",".",".","1"],
// ["7",".",".",".","2",".",".",".","6"],
// [".","6",".",".",".",".","2","8","."],
// [".",".",".","4","1","9",".",".","5"],
// [".",".",".",".","8",".",".","7","9"]]
// Output:
// [["5","3","4","6","7","8","9","1","2"],
// ["6","7","2","1","9","5","3","4","8"],
// ["1","9","8","3","4","2","5","6","7"],
// ["8","5","9","7","6","1","4","2","3"],
// ["4","2","6","8","5","3","7","9","1"],
// ["7","1","3","9","2","4","8","5","6"],
// ["9","6","1","5","3","7","2","8","4"],
// ["2","8","7","4","1","9","6","3","5"],
// ["3","4","5","2","8","6","1","7","9"]]

// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

#include <vector>
using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { solveSudoku2(board); }

  bool solveSudoku2(vector<vector<char>>& board) {
    int curRow = 0;
    int curCol = 0;
    if (isSudokuComplete(board, curRow, curCol)) {
      return true;
    }

    for (int k = 1; k < 10; k++) {
      if (!isNumberUsedInRow(board, curRow, k) &&
          !isNumberUsedInCol(board, curCol, k) &&
          !isNumberUsedInBox(board, curRow, curCol, k)) {
        board[curRow][curCol] = '0' + k;

        if (solveSudoku2(board)) {
          return true;
        }

        board[curRow][curCol] = '.';
      }
    }

    return false;
  }

  bool isSudokuComplete(vector<vector<char>>& board, int& curRow, int& curCol) {
    for (curRow = 0; curRow < 9; curRow++) {
      for (curCol = 0; curCol < 9; curCol++) {
        if (board[curRow][curCol] == '.') {
          return false;
        }
      }
    }
    return true;
  }

  bool isNumberUsedInRow(vector<vector<char>>& board, int row, int num) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == '0' + num) {
        return true;
      }
    }
    return false;
  }

  bool isNumberUsedInCol(vector<vector<char>>& board, int col, int num) {
    for (int i = 0; i < 9; i++) {
      if (board[i][col] == '0' + num) {
        return true;
      }
    }
    return false;
  }

  bool isNumberUsedInBox(vector<vector<char>>& board, int row, int col,
                         int num) {
    int top = 0;
    int left = 0;
    if (row >= 3 && row < 6) {
      top = 3;
    } else if (row >= 6) {
      top = 6;
    }
    if (col >= 3 && col < 6) {
      left = 3;
    } else if (col >= 6) {
      left = 6;
    }
    for (int i = top; i < top + 3; i++) {
      for (int j = left; j < left + 3; j++) {
        if (board[i][j] == '0' + num) {
          return true;
        }
      }
    }
    return false;
  }
};