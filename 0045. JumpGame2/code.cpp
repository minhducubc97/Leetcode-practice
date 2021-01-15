// Given an array of non-negative integers nums, you are initially positioned at
// the first index of the array. Each element in the array represents your
// maximum jump length at that position. Your goal is to reach the last index in
// the minimum number of jumps. You can assume that you can always reach the
// last index.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
// step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:
// 1 <= nums.length <= 3 * 10^4
// 0 <= nums[i] <= 10^5

#include <vector>
using namespace std;

class Solution {
 public:
  int min(int a, int b) { return (a < b) ? a : b; }
  int jump(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
    if (nums[0] == 0) return INT_MAX;

    vector<int> jumps(nums.size(), INT_MAX);
    jumps[0] = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = min(nums.size() - 1, i + nums[i]); j > i; j--) {
        if (jumps[j] >= jumps[i] + 1)
          jumps[j] = jumps[i] + 1;
        else
          break;
      }
    }

    return jumps[jumps.size() - 1];
  }
};