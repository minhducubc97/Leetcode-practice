// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<int> toDo;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') toDo.insert(i * 1000 + j);
            }
        }
        while (!toDo.empty()) {
            auto cell = *(toDo.begin());
            int row = cell / 1000;
            int col = cell % 1000;
            visitIsland(grid, toDo, row, col);
            ++count;
        }
        return count;
    }
    
    void visitIsland(vector<vector<char>>& grid, unordered_set<int>& toDo, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return;
        }
        auto search = toDo.find(row * 1000 + col);
        if (search != toDo.end()) {
            toDo.erase(search);
            visitIsland(grid, toDo, row - 1, col);
            visitIsland(grid, toDo, row + 1, col);
            visitIsland(grid, toDo, row, col - 1);
            visitIsland(grid, toDo, row, col + 1);
        }
    }
};