class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode *> s;
      TreeNode *curr = root;
      vector<int> result;
  
      while (curr != nullptr)
      {
          while (curr !=  nullptr)
          {
              s.push(curr);
              curr = curr->left;
          }
  
          curr = s.top();
          s.pop();
  
          result.push_back(curr->val);
  
          curr = curr->right;
      }

      return result;
    }
}