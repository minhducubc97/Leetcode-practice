// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other. Given an integer n, return all
// distinct solutions to the n-queens puzzle. Each solution contains a distinct
// board configuration of the n-queens' placement, where 'Q' and '.' both
// indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    string rowStr(n, '.');
    vector<string> board(n, rowStr);
    solveNQueensSub(result, board, 0);
    return result;
  }

  void solveNQueensSub(vector<vector<string>>& result, vector<string>& board,
                       int curRow) {
    int n = board.size();
    if (curRow == n) {
      result.push_back(board);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (isValid(board, curRow, i)) {
        board[curRow][i] = 'Q';
        solveNQueensSub(result, board, curRow + 1);
        board[curRow][i] = '.';
      }
    }
  }

  bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++)
      if (board[i][col] == 'Q') return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
      if (board[i][j] == 'Q') return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
      if (board[i][j] == 'Q') return false;
    return true;
  }
};