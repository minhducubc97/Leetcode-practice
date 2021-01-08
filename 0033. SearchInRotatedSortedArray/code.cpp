// You are given an integer array nums sorted in ascending order (with distinct
// values), and an integer target. Suppose that nums is rotated at some pivot
// unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become
// [4,5,6,7,0,1,2]). If target is found in the array return its index,
// otherwise, return -1.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// Constraints:
// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int minIdx = findSmallest(nums, 0, nums.size() - 1);
    cout << minIdx << endl;
    if (target > nums[nums.size() - 1]) {
      return binarySearch(nums, target, 0, minIdx - 1);
    } else {
      return binarySearch(nums, target, minIdx, nums.size() - 1);
    }
  }

  int binarySearch(vector<int>& nums, int target, int startIdx, int endIdx) {
    if (startIdx >= endIdx) {
      return (nums[startIdx] == target) ? startIdx : -1;
    }

    int midIdx = (endIdx - startIdx) / 2 + startIdx;
    if (nums[midIdx] == target) {
      return midIdx;
    } else if (nums[midIdx] < target) {
      return binarySearch(nums, target, midIdx + 1, endIdx);
    } else {
      return binarySearch(nums, target, startIdx, midIdx - 1);
    }
  }

  int findSmallest(vector<int>& nums, int startIdx, int endIdx) {
    if (startIdx >= endIdx) {
      return startIdx;
    }
    int midIdx = (endIdx - startIdx) / 2 + startIdx;
    if (nums[midIdx] <= nums[endIdx]) {
      if (midIdx == 0) {
        return midIdx;
      } else {
        if (nums[midIdx - 1] > nums[midIdx]) {
          return midIdx;
        } else {
          return findSmallest(nums, startIdx, midIdx);
        }
      }
    } else {
      return findSmallest(nums, midIdx + 1, endIdx);
    }
  }
};