// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Example 1:
// Input: n = 3
// Output: 5

// Example 2:
// Input: n = 1
// Output: 1

// Constraints:
// 1 <= n <= 19

class Solution {
public:
    int numTrees(int n) {
        vector<int> memoiz(n, 0);
        memoiz[0] = 1;
        return numTreesHelper(1, n, memoiz);
    }
    
    int numTreesHelper(int start, int end, vector<int>& memoiz) {
        if (start >= end) return 1;
        int sum = 0;
        sum += numTreesHelper(start + 1, end, memoiz);
        sum += numTreesHelper(start, end - 1, memoiz);
        for (int i = start + 1; i < end; i++) {
            if (i - 1 - start > 0 && memoiz[i - 1 - start] == 0) {
                memoiz[i - 1 - start] = numTreesHelper(start, i - 1, memoiz);
            }
            if (end - i - 1 > 0 && memoiz[end - i - 1] == 0) {
                memoiz[end - i - 1] = numTreesHelper(i + 1, end, memoiz);
            }
            sum += memoiz[i - 1 - start] * memoiz[end - i - 1];
        }
        return sum;
    }
};