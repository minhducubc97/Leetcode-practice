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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr) return root1;
        if (root1 == nullptr) return root2;
        queue<vector<TreeNode*>> toDo;
        toDo.push({root1, root2});
        while (!toDo.empty()) {
            auto rootPair = toDo.front();
            toDo.pop();
            TreeNode* root1Node = rootPair[0];
            TreeNode* root2Node = rootPair[1];
            root1Node->val += root2Node->val;
             
            if (root1Node->left == nullptr) root1Node->left = root2Node->left;
            else if (root2Node->left != nullptr) {
                toDo.push({root1Node->left, root2Node->left});
            }
            if (root1Node->right == nullptr) root1Node->right = root2Node->right;
            else if (root2Node->right != nullptr) {
                toDo.push({root1Node->right, root2Node->right});
            }
        }
        return root1;
    }
};