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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> curVec;
        pathSumHelper(root, result, curVec, 0, sum);
        return result;
    }
    
    void pathSumHelper(TreeNode* root, vector<vector<int>>& result, vector<int>& curVec, int curSum, int targetSum) {
        if (root == nullptr) return;
        curVec.push_back(root->val);
        pathSumHelper(root->left, result, curVec, curSum + root->val, targetSum);
        pathSumHelper(root->right, result, curVec, curSum + root->val, targetSum);
        if ((curSum + root->val == targetSum) && (root->right == nullptr) && (root->left == nullptr)) result.push_back(curVec);
        curVec.pop_back();
    }
};