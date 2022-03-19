// Given the head of a linked list, remove the nth node from the end of the list
// and return its head. Follow up: Could you do this in one pass?

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* toEnd = head;
        ListNode* prev = head;
        while (n > 0) {
            toEnd = toEnd->next;
            --n;
        }
        if (toEnd == nullptr) {
            return head->next;
        }
        while (toEnd->next != nullptr) {
            toEnd = toEnd->next;
            prev = prev->next;
        }
        ListNode* toDel = prev->next;
        prev->next = toDel->next;
        return head;
    }
};