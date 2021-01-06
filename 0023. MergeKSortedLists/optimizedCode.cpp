#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  struct compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
  };

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
      return nullptr;
    else if (lists.size() == 1)
      return lists[0];

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) pq.push(lists[i]);
    }

    if (pq.empty()) {
      return nullptr;
    }

    ListNode* head = new ListNode();
    ListNode* prev = head;
    while (!pq.empty()) {
      ListNode* cur = pq.top();
      pq.pop();
      prev->next = cur;
      prev = cur;
      if (cur->next != nullptr) {
        ListNode* after = cur->next;
        pq.push(cur->next);
      }
    }

    head = head->next;
    return head;
  }
};