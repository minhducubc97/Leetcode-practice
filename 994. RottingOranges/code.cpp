// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        queue<vector<int>> toDo;
        int result = 0;
        int countFresh = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == 2) {
                    toDo.push({i-1,j,1});
                    toDo.push({i+1,j,1});
                    toDo.push({i,j-1,1});
                    toDo.push({i,j+1,1});
                }
                if (grid[i][j] == 1) countFresh++;
            }
        }
        while (!toDo.empty()) {
            auto cell = toDo.front();
            toDo.pop();
            int row = cell[0];
            int col = cell[1];
            int min = cell[2];
            if (row < 0 || col < 0 || row >= numRows || col >= numCols) continue;
            if (grid[row][col] == 1) {
                grid[row][col] = 2;
                countFresh--;
                toDo.push({row-1,col,min+1});
                toDo.push({row+1,col,min+1});
                toDo.push({row,col-1,min+1});
                toDo.push({row,col+1,min+1});
                result = max(min, result);
            }
        }
        if (countFresh > 0) return -1;
        return result;
    }
};