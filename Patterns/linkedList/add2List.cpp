class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* a = NULL;
        ListNode* b = head;
        ListNode* c = head->next;
        while(b!=NULL){
            b->next=a;
            a=b;
            b=c;
            if(c!=NULL) c=c->next;
        }
        head=a;
        return head;
    }
    ListNode* sumup(ListNode* l1, ListNode* l2){
        ListNode* c = l1;
        bool a=false;
        while(l1->next!=NULL && l2->next!=NULL){
            l1->val = l1->val + l2->val;
            if(a){
                l1->val++;
                a=false;
            }
            if(l1->val>=10){
                l1->val=l1->val%10;
                a=true;
            }
            l1=l1->next;
            l2=l2->next;
        }
        l1->val = l1->val + l2->val;
        if(a){
            l1->val++;
            a=false;
        }
        if(l1->val>=10){
            l1->val=l1->val%10;
            a=true;
        }
        if(l1->next==NULL) l1->next=l2->next;
        if(l1->next==NULL){
            if(a){
                ListNode* z = new ListNode(1);
                l1->next=z;
            }
            return c;
        }
        l1=l1->next;
        while(l1->next!=NULL){
            if(a){
                l1->val++;
                a=false;
            }
            if(l1->val>=10){
                l1->val=l1->val%10;
                a=true;
            }
            l1=l1->next;
        }
        if(a){
            l1->val++;
            a=false;
        }
        if(l1->val>=10){
            l1->val=l1->val%10;
            a=true;
        }
        if(a){
            ListNode* z = new ListNode(1);
            l1->next=z;
        }
        return c;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* z = sumup(l1,l2);
        z = reverse(z);
        return z;
    }