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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(result, root, 0);
        return result;
    }
    
    void levelOrderHelper(vector<vector<int>>& result, TreeNode* root, int level) {
        if (root == nullptr) return;
        if (result.size() == level) result.push_back({});
        result[level].push_back(root->val);
        levelOrderHelper(result, root->left, level + 1);
        levelOrderHelper(result, root->right, level + 1);
    }
};