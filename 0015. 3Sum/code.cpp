// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero. Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:
// Input: nums = []
// Output: []

// Example 3:
// Input: nums = [0]
// Output: []

// Constraints:
// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int left;
    int right;
    int sum = 0;
    vector<vector<int>> result;
    string tripletStr;
    unordered_set<string> uset;

    if (nums.size() < 3) {
      return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      left = i + 1;
      right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] == sum) {
          tripletStr = to_string(nums[i]) + to_string(nums[left]) +
                       to_string(nums[right]);
          auto it = uset.find(tripletStr);
          if (it == uset.end()) {
            uset.insert(tripletStr);
            vector<int> triplet;
            triplet.push_back(nums[i]);
            triplet.push_back(nums[left]);
            triplet.push_back(nums[right]);
            result.push_back(triplet);
          }
          left++;
          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }
          right--;
          while (left < right && nums[right] == nums[right + 1]) {
            right--;
          }
        } else if (nums[i] + nums[left] + nums[right] < sum) {
          left++;
        } else {
          right--;
        }
      }
    }
    return result;
  }
};