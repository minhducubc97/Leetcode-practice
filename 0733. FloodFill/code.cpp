// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

// Return the modified image after performing the flood fill.

// Example 1:
// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Example 2:
// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
// Output: [[2,2,2],[2,2,2]]
 
// Constraints:
// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], newColor < 216
// 0 <= sr < m
// 0 <= sc < n

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int numRow = image.size();
        int numCol = image[0].size();
        int curColor = image[sr][sc];
        unordered_set<string> set;
        queue<vector<int>> toDo;
        toDo.push({sr, sc});
        while (!toDo.empty()) {
            auto toFill = toDo.front();
            toDo.pop();
            int row = toFill[0];
            int col = toFill[1];
            if (row < 0 || col < 0 || row >= numRow || col >= numCol) continue;
            if (image[row][col] != curColor) continue;
            string coord = to_string(row) + to_string(col);
            if (set.find(coord) != set.end()) continue;
            set.insert(coord);
            image[row][col] = newColor;
            toDo.push({row - 1, col});
            toDo.push({row + 1, col});
            toDo.push({row, col - 1});
            toDo.push({row, col + 1});
        }
        return image;
    }
};