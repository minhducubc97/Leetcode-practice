// Given a rows x cols binary matrix filled with 0's and 1's, find the largest
// rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix =
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:
// Input: matrix = []
// Output: 0

// Example 3:
// Input: matrix = [["0"]]
// Output: 0

// Example 4:
// Input: matrix = [["1"]]
// Output: 1

// Example 5:
// Input: matrix = [["0","0"]]
// Output: 0

// Constraints:
// rows == matrix.length
// cols == matrix.length
// 0 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top(); s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};