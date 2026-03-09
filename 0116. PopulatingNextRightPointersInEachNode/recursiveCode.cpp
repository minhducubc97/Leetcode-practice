/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        Node* leftBranch = connect(root->left);
        Node* rightBranch = connect(root->right);
        while (leftBranch != nullptr && rightBranch != nullptr) {
            leftBranch->next = rightBranch;
            leftBranch = leftBranch->right;
            rightBranch = rightBranch->left;
        }
        return root;
    }
};