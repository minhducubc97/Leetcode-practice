// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> todo;
        vector<vector<int>> result;
        zigzagLevelOrderHelper(root, result, 0, true);
        return result;
    }
    
    void zigzagLevelOrderHelper(TreeNode* root, vector<vector<int>>& result, int level, bool insertLast) {
        if (root == nullptr) return;
        if (result.size() == level) result.push_back({});
        if (insertLast) result[level].push_back(root->val);
        else result[level].insert(result[level].begin(), root->val);
        zigzagLevelOrderHelper(root->left, result, level + 1, !insertLast);
        zigzagLevelOrderHelper(root->right, result, level + 1, !insertLast);
    }
};