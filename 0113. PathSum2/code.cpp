// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

// Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: []

// Example 3:
// Input: root = [1,2], targetSum = 0
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

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
        if (root == nullptr) {
            return {};
        }
        
        queue<TreeNode*> todo;
        todo.push(root);
        queue<int> sumQ;
        sumQ.push(root->val);
        queue<vector<int>> path;
        path.push({root->val});
        vector<vector<int>> result;
        while (!todo.empty()) {
            TreeNode* curNode = todo.front();
            todo.pop();
            int curSum = sumQ.front();
            sumQ.pop();
            vector<int> curPath = path.front();
            path.pop();
            vector<int> curPath2;
            curPath2.assign(curPath.begin(), curPath.end());
            
            if (curNode->right == nullptr && curNode->left == nullptr) {
                if (curSum == sum) {
                    result.push_back(curPath);
                }
            }
            if (curNode->right != nullptr) {
                todo.push(curNode->right);
                sumQ.push(curSum + curNode->right->val);
                curPath.push_back(curNode->right->val);
                path.push(curPath);
            }
            if (curNode->left != nullptr) {
                todo.push(curNode->left);
                sumQ.push(curSum + curNode->left->val);
                curPath2.push_back(curNode->left->val);
                path.push(curPath2);
            }
        }
        
        return result;
    }
};