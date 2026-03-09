// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:
// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, postorder.size() - 1, 0, postorder.size() - 1);   
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int postIdx, int leftInIdx, int rightInIdx) {
        int subRootInIdx = leftInIdx;
        for (int i = leftInIdx; i <= rightInIdx; i++) {
            if (inorder[i] == postorder[postIdx]) subRootInIdx = i;
        }
        TreeNode* result = new TreeNode(postorder[postIdx]);
        if (leftInIdx <= subRootInIdx - 1) {
            result->left = buildTreeHelper(inorder, postorder, postIdx - (rightInIdx - subRootInIdx) - 1, leftInIdx, subRootInIdx - 1);
        }
        if (subRootInIdx + 1 <= rightInIdx) {
            result->right = buildTreeHelper(inorder, postorder, postIdx - 1, subRootInIdx + 1, rightInIdx);
        }
        return result;
    }
};