// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]

// Constraints:
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curPath;
        queue<int> toDo;
        for (int i = 0; i < nums.size(); i++) toDo.push(nums[i]);
        permuteHelper(result, toDo, curPath);
        return result;
    }
    
    void permuteHelper(vector<vector<int>>& result, queue<int>& toDo, vector<int>& curPath) {
        if (toDo.empty()) result.push_back(curPath);
        int size = toDo.size();
        for (int i = 0; i < size; i++) {
            int element = toDo.front();
            toDo.pop();
            curPath.push_back(element);
            permuteHelper(result, toDo, curPath);
            curPath.pop_back();
            toDo.push(element);
        }
    }
};