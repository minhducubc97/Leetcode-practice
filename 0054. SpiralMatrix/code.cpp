// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    spiralOrderSub(result, matrix, 0, 0, matrix.size() - 1,
                   matrix[0].size() - 1, 1, 0, 0);
    return result;
  }

  void spiralOrderSub(vector<int>& result, vector<vector<int>>& matrix, int row,
                      int col, int rowUpperLimit, int colUpperLimit,
                      int rowLowerLimit, int colLowerLimit, int state) {
    if (result.size() == matrix.size() * matrix[0].size()) return;
    result.push_back(matrix[row][col]);
    // state = 0 : left to right
    // state = 1 : top to bottom
    // state = 2 : right to left
    // state = 3 : bottom to top
    if (state == 0) {
      if (col == colUpperLimit)
        spiralOrderSub(result, matrix, row + 1, col, rowUpperLimit,
                       colUpperLimit - 1, rowLowerLimit, colLowerLimit, 1);
      else
        spiralOrderSub(result, matrix, row, col + 1, rowUpperLimit,
                       colUpperLimit, rowLowerLimit, colLowerLimit, 0);

    } else if (state == 1) {
      if (row == rowUpperLimit)
        spiralOrderSub(result, matrix, row, col - 1, rowUpperLimit - 1,
                       colUpperLimit, rowLowerLimit, colLowerLimit, 2);
      else
        spiralOrderSub(result, matrix, row + 1, col, rowUpperLimit,
                       colUpperLimit, rowLowerLimit, colLowerLimit, 1);
    } else if (state == 2) {
      if (col == colLowerLimit)
        spiralOrderSub(result, matrix, row - 1, col, rowUpperLimit,
                       colUpperLimit, rowLowerLimit, colLowerLimit + 1, 3);
      else
        spiralOrderSub(result, matrix, row, col - 1, rowUpperLimit,
                       colUpperLimit, rowLowerLimit, colLowerLimit, 2);
    } else if (state == 3) {
      if (row == rowLowerLimit)
        spiralOrderSub(result, matrix, row, col + 1, rowUpperLimit,
                       colUpperLimit, rowLowerLimit + 1, colLowerLimit, 0);
      else
        spiralOrderSub(result, matrix, row - 1, col, rowUpperLimit,
                       colUpperLimit, rowLowerLimit, colLowerLimit, 3);
    }
  }
};