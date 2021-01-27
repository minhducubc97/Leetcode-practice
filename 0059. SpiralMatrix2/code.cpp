// Given a positive integer n, generate an n x n matrix filled with elements
// from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

// Constraints:
// 1 <= n <= 20

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<int> row(n);
    vector<vector<int>> result(n, row);
    generateCell(result, 0, 0, n - 1, n - 1, 1, 0, 0, 1);
    return result;
  }

  void generateCell(vector<vector<int>>& result, int row, int col,
                    int rowUpperLimit, int colUpperLimit, int rowLowerLimit,
                    int colLowerLimit, int state, int val) {
    int n = result.size();
    if (val == n * n + 1) return;
    result[row][col] = val;
    if (state == 0) {
      if (col == colUpperLimit)
        generateCell(result, row + 1, col, rowUpperLimit, colUpperLimit - 1,
                     rowLowerLimit, colLowerLimit, 1, val + 1);
      else
        generateCell(result, row, col + 1, rowUpperLimit, colUpperLimit,
                     rowLowerLimit, colLowerLimit, state, val + 1);
    } else if (state == 1) {
      if (row == rowUpperLimit)
        generateCell(result, row, col - 1, rowUpperLimit - 1, colUpperLimit,
                     rowLowerLimit, colLowerLimit, 2, val + 1);
      else
        generateCell(result, row + 1, col, rowUpperLimit, colUpperLimit,
                     rowLowerLimit, colLowerLimit, state, val + 1);
    } else if (state == 2) {
      if (col == colLowerLimit)
        generateCell(result, row - 1, col, rowUpperLimit, colUpperLimit,
                     rowLowerLimit, colLowerLimit + 1, 3, val + 1);
      else
        generateCell(result, row, col - 1, rowUpperLimit, colUpperLimit,
                     rowLowerLimit, colLowerLimit, state, val + 1);
    } else if (state == 3) {
      if (row == rowLowerLimit) {
        generateCell(result, row, col + 1, rowUpperLimit, colUpperLimit,
                     rowLowerLimit + 1, colLowerLimit, 0, val + 1);
      } else
        generateCell(result, row - 1, col, rowUpperLimit, colUpperLimit,
                     rowLowerLimit, colLowerLimit, state, val + 1);
    }
  }
};