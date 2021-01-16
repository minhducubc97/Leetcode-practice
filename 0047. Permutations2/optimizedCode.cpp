#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int>& numsCopy(nums);
    sort(numsCopy.begin(), numsCopy.end());
    vector<bool> visited(nums.size(), false);
    vector<vector<int>> result;
    vector<int> curPermutation;
    permuteUniqueDFS(numsCopy, result, curPermutation, visited, 0);
    return result;
  }

  void permuteUniqueDFS(vector<int>& nums, vector<vector<int>>& result,
                        vector<int>& curPermutation, vector<bool>& visited,
                        int curLevel) {
    if (curLevel == nums.size()) {
      result.push_back(curPermutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
        continue;
      visited[i] = true;
      curPermutation.push_back(nums[i]);
      permuteUniqueDFS(nums, result, curPermutation, visited, curLevel + 1);
      curPermutation.pop_back();
      visited[i] = false;
    }
  }
};