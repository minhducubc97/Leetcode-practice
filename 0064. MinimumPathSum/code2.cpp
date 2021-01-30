#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (m == 0 || n == 0) return 0;
    vector<int> dp(n);
    dp[0] = grid[0][0];
    for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + grid[0][i];
    for (int i = 1; i < m; i++) {
      dp[0] = dp[0] + grid[i][0];
      for (int j = 1; j < n; j++) dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
    }
    return dp[n - 1];
  }
};