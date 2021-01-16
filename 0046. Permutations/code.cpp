// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]

// Constraints:
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> visited(nums.size(), false);
    vector<int> curPermutation;
    permuteDFS(nums, result, visited, curPermutation, 0);
    return result;
  }

  void permuteDFS(vector<int>& nums, vector<vector<int>>& result,
                  vector<bool>& visited, vector<int>& curPermutation,
                  int level) {
    if (level == nums.size()) {
      result.push_back(curPermutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) continue;
      visited[i] = true;
      curPermutation.push_back(nums[i]);
      permuteDFS(nums, result, visited, curPermutation, level + 1);
      curPermutation.pop_back();
      visited[i] = false;
    }
  }
};