// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array
// [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
// are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int curMax = 0;
    vector<int> leftWall_height(height.size());
    for (int i = 0; i < height.size(); i++) {
      curMax = (height[i] > curMax) ? height[i] : curMax;
      leftWall_height[i] = curMax;
    }

    curMax = 0;
    vector<int> rightWall_height(height.size());
    for (int i = height.size() - 1; i >= 0; i--) {
      curMax = (height[i] > curMax) ? height[i] : curMax;
      rightWall_height[i] = curMax;
    }

    int result = 0;
    for (int i = 0; i < height.size(); i++) {
      result += (leftWall_height[i] < rightWall_height[i])
                    ? leftWall_height[i] - height[i]
                    : rightWall_height[i] - height[i];
    }

    return result;
  }
};