// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
 
// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
        }
    }
};