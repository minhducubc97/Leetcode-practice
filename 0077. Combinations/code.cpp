// Given two integers n and k, return all possible combinations of k numbers out
// of 1 ... n. You may return the answer in any order.

// Example 1:
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Example 2:
// Input: n = 1, k = 1
// Output: [[1]]

// Constraints:
// 1 <= n <= 20
// 1 <= k <= n

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> curCom;
    vector<bool> visited(n + 1, false);
    combineSub(result, curCom, visited, k, 1);
    return result;
  }

  void combineSub(vector<vector<int>>& result, vector<int>& curCom,
                  vector<bool>& visited, int k, int idx) {
    if (curCom.size() == k) {
      result.push_back(curCom);
      return;
    }
    for (; idx < visited.size(); idx++) {
      if (visited[idx]) continue;
      curCom.push_back(idx);
      visited[idx] = true;
      combineSub(result, curCom, visited, k, idx + 1);
      curCom.pop_back();
      visited[idx] = false;
    }
  }
};