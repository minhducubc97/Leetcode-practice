// Given an array nums of n integers and an integer target, find three integers
// in nums such that the sum is closest to target. Return the sum of the three
// integers. You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Constraints:
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }

    sort(nums.begin(), nums.end());

    int left;
    int right;
    int currClosestSum = nums[0] + nums[1] + nums[2];
    int sum;
    for (int i = 0; i < nums.size() - 2; i++) {
      left = i + 1;
      right = nums.size() - 1;

      while (left < right) {
        sum = nums[left] + nums[i] + nums[right];
        if (abs(target - sum) < abs(target - currClosestSum)) {
          currClosestSum = sum;
        }
        if (sum == target) {
          return target;
        }

        else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }

    return currClosestSum;
  }
};