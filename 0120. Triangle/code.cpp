// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:
// Input: triangle = [[-10]]
// Output: -10
 
// Constraints:
// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pathSums;
        minimumTotal(triangle, pathSums, 0, 0, 0);
        sort(pathSums.begin(), pathSums.end());
        return pathSums[0];
    }
    
    void minimumTotal(vector<vector<int>>& triangle, vector<int>& pathSums, int curSum, int parentIdx, int level) {
        int size = triangle.size();
        if (level == size) pathSums.push_back(curSum);
        else {
            curSum += triangle[level][parentIdx];
            minimumTotal(triangle, pathSums, curSum, parentIdx, level + 1);
            minimumTotal(triangle, pathSums, curSum, parentIdx + 1, level + 1);
        }
    }
};