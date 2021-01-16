// Given a collection of numbers, nums, that might contain duplicates, return
// all possible unique permutations in any order.

// Example 1:
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Constraints:
// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int>& numsCopy(nums);
    sort(numsCopy.begin(), numsCopy.end());
    vector<bool> visited(nums.size(), false);
    vector<vector<int>> result;
    vector<int> curPermutation;
    vector<int> level(nums.size(), -1);
    permuteUniqueDFS(numsCopy, result, curPermutation, visited, level, 0);
    return result;
  }

  void permuteUniqueDFS(vector<int>& nums, vector<vector<int>>& result,
                        vector<int>& curPermutation, vector<bool>& visited,
                        vector<int>& level, int curLevel) {
    if (curLevel == nums.size()) {
      result.push_back(curPermutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      level[i] = curLevel;
      if (visited[i] ||
          (i > 0 && nums[i] == nums[i - 1] && level[i - 1] == curLevel))
        continue;
      visited[i] = true;
      curPermutation.push_back(nums[i]);
      permuteUniqueDFS(nums, result, curPermutation, visited, level,
                       curLevel + 1);
      curPermutation.pop_back();
      visited[i] = false;
    }
  }
};