// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties: Integers in each row are sorted
// from left to right. The first integer of each row is greater than the last
// integer of the previous row.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return searchMatrixSub(matrix, target, 0, matrix.size() - 1, 0,
                           matrix[0].size() - 1);
  }

  bool searchMatrixSub(vector<vector<int>>& matrix, int target, int bottom,
                       int top, int left, int right) {
    if (bottom > top) return false;
    int midHeight = (top + bottom) / 2;
    if (matrix[midHeight][left] > target)
      return searchMatrixSub(matrix, target, bottom, midHeight - 1, left,
                             right);
    else if (matrix[midHeight][right] < target)
      return searchMatrixSub(matrix, target, midHeight + 1, top, left, right);
    else {
      if (left > right) return false;
      int midRow = (left + right) / 2;
      if (matrix[midHeight][midRow] > target)
        return searchMatrixSub(matrix, target, bottom, top, left, midRow - 1);
      else if (matrix[midHeight][midRow] < target)
        return searchMatrixSub(matrix, target, bottom, top, midRow + 1, right);
      else
        return true;
    }
  }
};