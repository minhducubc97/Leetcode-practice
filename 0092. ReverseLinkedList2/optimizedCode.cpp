class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head->next == nullptr) return head;
        
        ListNode* preLeftNode = nullptr;
        ListNode* leftNode = head;
        
        if (left != 1) {
            preLeftNode = head;
            for (int i = 2; i < left; i++) {
                preLeftNode = preLeftNode->next;
            }
            leftNode = preLeftNode->next;
        }
        
        ListNode* nextNode = leftNode->next;
        ListNode* currNode = leftNode;
        ListNode* prevNode = preLeftNode;
        int counter = left;
        while (counter <= right) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = (nextNode == nullptr) ? nullptr : nextNode->next;
            counter++;
        }
        
        if (preLeftNode != nullptr) {
            preLeftNode->next = prevNode;
        } else {
            head = prevNode;
        }
        leftNode->next = currNode;
        
        return head;
    }
};