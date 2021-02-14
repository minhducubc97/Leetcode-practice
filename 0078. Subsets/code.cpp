// Given an integer array nums of unique elements, return all possible subsets
// (the power set). The solution set must not contain duplicate subsets. Return
// the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    vector<int> curVec = {};
    subsetsSub(result, nums, curVec, 0, 0, 1, nums.size());
    return result;
  }

  void subsetsSub(vector<vector<int>>& result, vector<int>& nums,
                  vector<int>& curVec, int startIdx, int curCount,
                  int levelSize, int maxSize) {
    if (levelSize == maxSize) {
      for (int i = 0; i < nums.size(); i++) curVec.push_back(nums[i]);
      result.push_back(curVec);
      return;
    } else if (curCount == levelSize) {
      result.push_back(curVec);
      if (maxSize >= levelSize && curVec[0] == nums[maxSize - levelSize]) {
        curVec = {};
        subsetsSub(result, nums, curVec, 0, 0, levelSize + 1, maxSize);
      }
    } else {
      for (int i = startIdx; i <= nums.size() - levelSize + curCount; i++) {
        curVec.push_back(nums[i]);
        subsetsSub(result, nums, curVec, i + 1, curCount + 1, levelSize,
                   maxSize);
        curVec.pop_back();
      }
    }
  }
};