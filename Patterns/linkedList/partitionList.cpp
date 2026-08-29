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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* newdummyNode = new ListNode(-1);
        ListNode* slow = dummyNode;
        ListNode* fast = newdummyNode;
        dummyNode->next = temp;
        while(temp){
            if(temp->val < x){
                slow->next = temp;
                slow = slow->next;
            }
            else{
                fast->next = temp;
                fast = fast->next;
            }
            temp = temp->next;
        }
        fast->next = nullptr;
        slow->next = newdummyNode->next;
        return dummyNode->next;
    }
};