#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int tail = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (i + nums[i] >= tail) {
        tail = i;
      }
    }

    return (tail == 0);
  }
};