// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.

// Example 1:
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = new ListNode(), *prev = newHead, *cur = head, *next;
    newHead->next = head;
    int curVal;
    while (cur != nullptr) {
      next = cur->next;
      curVal = cur->val;
      if (next != nullptr) {
        if (next->val == curVal) {
          while (next != nullptr && next->val == curVal) {
            cur->next = next->next;
            next->next = nullptr;
            delete next;
            next = cur->next;
          }
          prev->next = next;
          cur->next = nullptr;
          delete cur;
          cur = next;
        } else {
          prev = cur;
          cur = next;
        }
      } else
        cur = next;
    }
    return newHead->next;
  }
};