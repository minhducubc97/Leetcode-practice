// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list. You may assume the two numbers do not contain any leading zero, except
// the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading
// zeros.

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *tail = new ListNode(0);
    ListNode *beforeLast = tail;
    ListNode *head = tail;
    int remaining = 0;
    int sum = 0;
    while (l1 != nullptr && l2 != nullptr) {
      sum = l1->val + l2->val + remaining;
      if (sum >= 10) {
        tail->val = sum % 10;
        remaining = sum / 10;
      } else {
        tail->val = sum;
        remaining = 0;
      }
      l1 = l1->next;
      l2 = l2->next;
      beforeLast = tail;
      tail->next = new ListNode(0);
      tail = tail->next;
    }
    while (l1 != nullptr) {
      if (remaining > 0) {
        tail->val = (l1->val + remaining) % 10;
        remaining = (l1->val + remaining) / 10;
      } else {
        tail->val = l1->val;
      }
      beforeLast = tail;
      tail->next = new ListNode(0);
      tail = tail->next;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      if (remaining > 0) {
        tail->val = (l2->val + remaining) % 10;
        remaining = (l2->val + remaining) / 10;
      } else {
        tail->val = l2->val;
      }
      beforeLast = tail;
      tail->next = new ListNode(0);
      tail = tail->next;
      l2 = l2->next;
    }
    if (remaining > 0) {
      tail->val = remaining;
    } else {
      beforeLast->next = nullptr;
      delete tail;
    }

    return head;
  }
};