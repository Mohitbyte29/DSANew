class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* slow = dummyNode;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            if(fast->val == fast->next->val){
                while(fast->next != NULL && fast->val == fast->next->val){
                    fast = fast->next;
                }
                slow->next = fast->next;
            }
            else{
                slow = slow->next;
            }
            fast = fast->next;
        }
        return dummyNode->next;
    }
};
