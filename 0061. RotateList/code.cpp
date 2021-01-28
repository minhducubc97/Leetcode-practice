// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    vector<ListNode*> llVector;
    ListNode* traversal = head;
    while (traversal != nullptr) {
      llVector.push_back(traversal);
      traversal = traversal->next;
    }
    int n = llVector.size(), pretail = n - 2, tail = n - 1, headV = 0;
    k %= n;
    while (k > 0) {
      llVector[tail]->next = llVector[headV];
      pretail = (tail == 0) ? n - 1 : tail - 1;
      llVector[pretail]->next = nullptr;
      headV = tail;
      tail = pretail;
      k--;
    }
    return llVector[headV];
  }
};