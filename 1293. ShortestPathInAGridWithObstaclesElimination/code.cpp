// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

// Example 1:
// Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
// Output: 6
// Explanation: 
// The shortest path without eliminating any obstacle is 10.
// The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

// Example 2:
// Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
// Output: -1
// Explanation: We need to eliminate at least two obstacles to find such a walk.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 40
// 1 <= k <= m * n
// grid[i][j] is either 0 or 1.
// grid[0][0] == grid[m - 1][n - 1] == 0

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<vector<int>> visited(numRows, vector<int>(numCols, -1));
        queue<vector<int>> toDo;
        // {x: curCol, y: curRow, curLength, curK}
        toDo.push({0 ,0 ,0, k});
        while (!toDo.empty()) {
            auto curCell = toDo.front();
            toDo.pop();
            int x = curCell[0];
            int y = curCell[1];
            int curLength = curCell[2];
            int curK = curCell[3];
            if (x == numCols - 1 && y == numRows - 1) {
                return curLength;
            }
            if (x < 0 || y < 0 || x >= numCols || y >= numRows) continue;
            if (grid[y][x] == 1) {
                if (curK > 0) {
                    curK--;
                } else continue;
            }
            if (visited[y][x] > -1 && visited[y][x] >= curK) continue;
            visited[y][x] = curK;
            toDo.push({x+1, y, curLength + 1, curK});
            toDo.push({x-1, y, curLength + 1, curK});
            toDo.push({x, y+1, curLength + 1, curK});
            toDo.push({x, y-1, curLength + 1, curK});
        }
        return -1;
    }
};