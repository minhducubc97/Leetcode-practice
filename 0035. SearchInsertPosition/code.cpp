// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Example 4:
// Input: nums = [1,3,5,6], target = 0
// Output: 0

// Example 5:
// Input: nums = [1], target = 0
// Output: 0

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return binarySearchInsertion(nums, target, 0, nums.size() - 1);
  }

  int binarySearchInsertion(vector<int>& nums, int target, int startIdx,
                            int endIdx) {
    if (startIdx == endIdx) {
      if (nums[startIdx] >= target) {
        return startIdx;
      } else {
        return startIdx + 1;
      }
    }

    int midIdx = (endIdx - startIdx) / 2 + startIdx;
    if (nums[midIdx] == target) {
      return midIdx;
    } else if (nums[midIdx] > target) {
      if (midIdx == startIdx) {
        return startIdx;
      } else if (nums[midIdx - 1] < target) {
        return midIdx;
      } else {
        return binarySearchInsertion(nums, target, startIdx, midIdx - 1);
      }
    } else {
      if (midIdx == endIdx) {
        return endIdx + 1;
      } else if (nums[midIdx + 1] > target) {
        return midIdx + 1;
      } else {
        return binarySearchInsertion(nums, target, midIdx + 1, endIdx);
      }
    }
  }
};