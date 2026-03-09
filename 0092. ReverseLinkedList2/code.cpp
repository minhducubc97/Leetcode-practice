// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:
// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head->next == nullptr) return head;
        
        ListNode* preLeftNode = nullptr;
        ListNode* leftNode = head;
        ListNode* postRightNode = head;
        
        if (left != 1) {
            preLeftNode = head;
            for (int i = 2; i < left; i++) {
                preLeftNode = preLeftNode->next;
            }
            leftNode = preLeftNode->next;
        }
        for (int j = 1; j <= right; j++) {
            postRightNode = postRightNode->next;
        }
        
        ListNode* nextNode = leftNode->next;
        ListNode* currNode = leftNode;
        ListNode* prevNode = preLeftNode;
        while (currNode != postRightNode) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = (nextNode == nullptr) ? nextNode : nextNode->next;
        }
        
        if (preLeftNode != nullptr) {
            preLeftNode->next = prevNode;
        } else {
            head = prevNode;
        }
        leftNode->next = postRightNode;
        
        return head;
    }
};