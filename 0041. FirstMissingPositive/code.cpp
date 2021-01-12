// Given an unsorted integer array nums, find the smallest missing positive
// integer. Follow up: Could you implement an algorithm that runs in O(n) time
// and uses constant extra space.?

// Example 1:
// Input: nums = [1,2,0]
// Output: 3

// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2

// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1

// Constraints:
// 0 <= nums.length <= 300
// -231 <= nums[i] <= 231 - 1

#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    if (nums.size() == 0) return 1;
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != i) {
        if (nums[i] < 0 || nums[i] >= nums.size() || nums[i] == nums[nums[i]])
          break;
        int temp = nums[i];
        nums[i] = nums[temp];
        nums[temp] = temp;
      }
    }

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != i) {
        return i;
      }
    }
    return (nums[0] == nums.size()) ? nums.size() + 1 : nums.size();
  }
};