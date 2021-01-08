// Given an array of integers nums sorted in ascending order, find the starting
// and ending position of a given target value. If target is not found in the
// array, return [-1, -1]. Follow up: Could you write an algorithm with O(log n)
// runtime complexity?

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) return {-1, -1};

    int targetIdx = binarySearch(nums, target, 0, nums.size() - 1);
    if (targetIdx == -1) return {-1, -1};

    int leftIdx = targetIdx - 1;
    int rightIdx = targetIdx + 1;
    vector<int> result;
    while (leftIdx >= 0 && nums[leftIdx] == nums[targetIdx]) {
      leftIdx--;
    }
    while (rightIdx <= nums.size() - 1 && nums[rightIdx] == nums[targetIdx]) {
      rightIdx++;
    }
    leftIdx++;
    rightIdx--;
    result.push_back(leftIdx);
    result.push_back(rightIdx);
    return result;
  }

  int binarySearch(vector<int>& nums, int target, int startIdx, int endIdx) {
    if (startIdx >= endIdx) {
      return (nums[startIdx] == target) ? startIdx : -1;
    }

    int midIdx = (endIdx - startIdx) / 2 + startIdx;
    if (nums[midIdx] == target) {
      return midIdx;
    } else if (nums[midIdx] > target) {
      return binarySearch(nums, target, startIdx, midIdx - 1);
    } else {
      return binarySearch(nums, target, midIdx + 1, endIdx);
    }
  }
};