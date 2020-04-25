
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){return NULL;}
        
        ListNode *slow=head,*fast=head;
        int i=0;
        while(i<n){fast=fast->next;i++;}
        if(fast==NULL){head=head->next; return head;}
        while(fast->next){
        	slow=slow->next;
        	fast=fast->next;
        }
        fast = slow->next;
        slow->next=slow->next->next;
        delete fast;
        return head;
    }
};