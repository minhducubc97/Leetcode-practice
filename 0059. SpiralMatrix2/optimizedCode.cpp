#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
    while (true) {
      for (int j = left; j <= right; ++j) result[up][j] = val++;
      if (++up > down) break;
      for (int i = up; i <= down; ++i) result[i][right] = val++;
      if (--right < left) break;
      for (int j = right; j >= left; --j) result[down][j] = val++;
      if (--down < up) break;
      for (int i = down; i >= up; --i) result[i][left] = val++;
      if (++left > right) break;
    }
    return result;
  }
};