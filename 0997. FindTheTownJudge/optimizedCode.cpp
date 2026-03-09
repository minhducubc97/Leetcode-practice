class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        if (trust.size() < n - 1) return -1;
        vector<int> numBelievers(n + 1, 0);
        vector<int> numTrusts(n + 1, 0);
        int judge = -1;
        for (auto edge : trust) {
            ++numTrusts[edge[0]];
            ++numBelievers[edge[1]];
            if (numBelievers[edge[1]] == n - 1) judge = edge[1];
        }
        if (judge != -1) {
            if (numTrusts[judge] == 0) return judge;
            return -1;
        }
        return judge;
    }
};