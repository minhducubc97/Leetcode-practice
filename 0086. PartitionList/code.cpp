// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        int count = 1;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
            ++count;
        }
        ListNode* tail = curr;
        curr = head;
        ListNode* prev = new ListNode(0, head);
        while (count-- > 0) {        
            if (curr->val >= x) {
                if (curr == head) {
                    head = head->next;
                }
                if (curr != tail) {
                    prev->next = curr->next;
                    curr->next = nullptr;
                    tail->next = curr;
                    tail = tail->next;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};