ListNode* findMid(ListNode* head){
	ListNode *fast=head->next, *slow=head;
	while(fast && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
ListNode* reverse(ListNode* head){
	ListNode *c=head, *p=NULL, *n;
	while(c){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	return p;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL){return true;}
        ListNode* mid= findMid(head);
        ListNode* L2= mid->next;
        mid->next=NULL;
        L2=reverse(L2);

        while(head && L2){
        	if(head->val != L2->val){
        		return false;
        	}
        	head=head->next;
        	L2=L2->next;
        }
        return true;
    }
};