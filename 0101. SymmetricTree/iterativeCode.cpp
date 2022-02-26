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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> leftQ;
        queue<TreeNode*> rightQ;
        leftQ.push(root->left);
        rightQ.push(root->right);
        while (!leftQ.empty() && !rightQ.empty()) {
            TreeNode* topLeftQ = leftQ.front();
            TreeNode* topRightQ = rightQ.front();
            leftQ.pop();
            rightQ.pop();
            if (topLeftQ == nullptr && topRightQ == nullptr) continue;
            else if (topLeftQ == nullptr || topRightQ == nullptr || (topLeftQ->val != topRightQ->val)) return false;
            leftQ.push(topLeftQ->left);
            leftQ.push(topLeftQ->right);
            rightQ.push(topRightQ->right);
            rightQ.push(topRightQ->left);
        }
        return true;
    }
};