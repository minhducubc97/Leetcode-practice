// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target. Notice that the
// solution set must not contain duplicate quadruplets.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [], target = 0
// Output: []

// Constraints:
// 0 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return allSum(nums, target, 0, 4);
  }

  vector<vector<int>> allSum(vector<int>& nums, int target, int startIdx,
                             int noSum) {
    vector<vector<int>> result;
    if (startIdx == nums.size() || nums[startIdx] * noSum > target ||
        nums.back() * noSum < target) {
      return result;
    }
    if (noSum == 2) {
      return twoSum(nums, target, startIdx);
    }
    for (int i = startIdx; i < nums.size(); i++) {
      if (i == startIdx || nums[i - 1] != nums[i]) {
        vector<vector<int>> curSets =
            allSum(nums, target - nums[i], i + 1, noSum - 1);
        for (auto& set : curSets) {
          result.push_back({nums[i]});
          result.back().insert(end(result.back()), begin(set), end(set));
        }
      }
    }
    return result;
  }

  vector<vector<int>> twoSum(vector<int>& nums, int target, int startIdx) {
    vector<vector<int>> result;
    int left = startIdx;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum > target ||
          (right < nums.size() - 1 && nums[right] == nums[right + 1])) {
        right--;
      } else if (sum < target ||
                 (left > startIdx && nums[left] == nums[left - 1])) {
        left++;
      } else {
        result.push_back({nums[left], nums[right]});
        left++;
        right--;
      }
    }
    return result;
  }
};