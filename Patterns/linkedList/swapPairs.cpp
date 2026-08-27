class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        ListNode* newHead = temp->next;
        prev->next = swapPairs(newHead);
        temp->next = prev;
        return temp;
    }
};
