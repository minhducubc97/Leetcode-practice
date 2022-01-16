using namespace std;

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