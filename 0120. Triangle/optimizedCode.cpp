class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> prev = triangle[0];
        vector<int> cur = triangle[0];
        for (int i = 1; i < size; i++) {
            cur = triangle[i];
            cur[0] += prev[0];
            for (int j = 1; j < cur.size() - 1; j++) {
                cur[j] += min(prev[j - 1], prev[j]);
            }
            cur[cur.size() - 1] += prev[prev.size() - 1];
            prev = cur;
        }
        sort(cur.begin(), cur.end());
        return cur[0];
    }
};