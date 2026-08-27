//* Without slow-Fast pointer approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int num = 0;
        while(temp != NULL){
            num++;
            temp = temp->next;
        }
        if (n == num) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        int target = num - n;
        num = 0;
        for(int i = 1; i < target; i++){
            temp = temp->next;
        }
        ListNode* targetNode = temp->next;
        temp->next = targetNode->next;
        delete targetNode;
        return head;
    }
};

//* With slow-Fast pointer approach
