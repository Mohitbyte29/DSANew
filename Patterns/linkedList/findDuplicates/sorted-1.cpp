/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            if(fast->val == fast->next->val) {
                fast = fast->next;
            }
            else{
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = fast;
        }
        return dummy->next;
    }
};