// Given an m x n board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells,
// where "adjacent" cells are horizontally or vertically neighboring. The same
// letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "ABCCED" Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "SEE" Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "ABCB" Output: false

// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 200
// 1 <= word.length <= 103
// board and word consists only of lowercase and uppercase English letters.

#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        visited[i][j] = true;
        if (validCell(board, visited, word, 0, i, j)) return true;
        visited[i][j] = false;
      }
    }
    return false;
  }

  bool validCell(vector<vector<char>>& board, vector<vector<bool>>& visited,
                 string word, int charIdx, int row, int col) {
    visited[row][col] = true;
    if (board[row][col] == word[charIdx]) {
      if ((charIdx == word.size() - 1) ||
          ((row > 0 && !visited[row - 1][col] &&
            validCell(board, visited, word, charIdx + 1, row - 1, col)) ||
           (col > 0 && !visited[row][col - 1] &&
            validCell(board, visited, word, charIdx + 1, row, col - 1)) ||
           (row < board.size() - 1 && !visited[row + 1][col] &&
            validCell(board, visited, word, charIdx + 1, row + 1, col)) ||
           (col < board[0].size() - 1 && !visited[row][col + 1] &&
            validCell(board, visited, word, charIdx + 1, row, col + 1))))
        return true;
    }
    visited[row][col] = false;
    return false;
  }
};