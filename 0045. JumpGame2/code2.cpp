#include <vector>
using namespace std;

class Solution {
 public:
  int max(int a, int b) { return (a > b) ? a : b; }

  int jump(vector<int>& nums) {
    int curLongestStep = 0, i = 0, level = 0;

    while (curLongestStep < nums.size() - 1) {
      level++;  // BFS level
      int curLongestStepCopy = curLongestStep;
      for (; i <= curLongestStepCopy;
           i++) {  // traverse of preStep level and find
                   // the max step of this level
        curLongestStep = max(curLongestStep, i + nums[i]);
      }
    }

    return level;
  }
};