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
    ListNode* prev = head;
    ListNode* tail = head;
    ListNode* toDel = head;
    ListNode* nextt = head;
    if (head == NULL) {
      return NULL;
    }
    for (int i = 1; i < n; i++) {
      tail = tail->next;
    }
    while (tail->next != NULL) {
      tail = tail->next;
      prev = toDel;
      toDel = toDel->next;
    }
    if (toDel == head) {
      return toDel->next;
    } else {
      nextt = toDel->next;
      delete (toDel);
      toDel = NULL;
      prev->next = nextt;
      return head;
    }
  }
};