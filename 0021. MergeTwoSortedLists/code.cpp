// Merge two sorted linked lists and return it as a new sorted list. The new
// list should be made by splicing together the nodes of the first two lists.

// Example 1:
// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: l1 = [], l2 = []
// Output: []

// Example 3:
// Input: l1 = [], l2 = [0]
// Output: [0]

// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.

#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
      return l2;
    }
    if (l2 == NULL) {
      return l1;
    }
    ListNode* result = new ListNode(0);
    ListNode* resultHead = result;
    while (l1 != NULL || l2 != NULL) {
      if (l1 == NULL) {
        result->next = new ListNode(l2->val);
        l2 = l2->next;
      } else if (l2 == NULL) {
        result->next = new ListNode(l1->val);
        l1 = l1->next;
      } else if (l1->val <= l2->val) {
        result->next = new ListNode(l1->val);
        l1 = l1->next;
      } else if (l1->val > l2->val) {
        result->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      result = result->next;
    }
    result = resultHead->next;
    resultHead->next = NULL;
    delete (resultHead);

    return result;
  }
};