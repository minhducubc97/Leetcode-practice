// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers. If such an arrangement
// is not possible, it must rearrange it as the lowest possible order (i.e.,
// sorted in ascending order). The replacement must be in place and use only
// constant extra memory.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:
// Input: nums = [1,1,5]
// Output: [1,5,1]

// Example 4:
// Input: nums = [1]
// Output: [1]

// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int firstDecrement = nums.size();
    for (int i = nums.size() - 1; i > 0; i--) {
      if (nums[i] > nums[i - 1]) {
        firstDecrement = i - 1;
        break;
      }
    }
    if (firstDecrement == nums.size()) {
      sort(nums.begin(), nums.end());
      return;
    }

    int minGreaterValue = nums[firstDecrement + 1];
    int minGreaterIdx = firstDecrement + 1;
    for (int i = nums.size() - 1; i > firstDecrement; i--) {
      if (nums[i] > nums[firstDecrement] && minGreaterValue > nums[i]) {
        minGreaterIdx = i;
        minGreaterValue = nums[i];
      }
    }

    int temp = nums[firstDecrement];
    nums[firstDecrement] = nums[minGreaterIdx];
    nums[minGreaterIdx] = temp;

    sort(nums.begin() + firstDecrement + 1, nums.end());
  }
};