// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other. Given an integer n, return the
// number of distinct solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as
// shown.

// Example 2:
// Input: n = 1
// Output: 1

// Constraints:
// 1 <= n <= 9

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    int count = 0;
    string row(n, '.');
    vector<string> board(n, row);
    int curRow = 0;
    totalNQueensSub(board, count, curRow);
    return count;
  }

  void totalNQueensSub(vector<string>& board, int& count, int curRow) {
    int n = board.size();
    if (curRow == n) {
      count++;
      return;
    }

    for (int i = 0; i < n; i++) {
      if (isValid(board, curRow, i)) {
        board[curRow][i] = 'Q';
        totalNQueensSub(board, count, curRow + 1);
        board[curRow][i] = '.';
      }
    }
  }

  bool isValid(vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++)
      if (board[i][col] == 'Q') return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
      if (board[i][j] == 'Q') return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
      if (board[i][j] == 'Q') return false;
    return true;
  }
};