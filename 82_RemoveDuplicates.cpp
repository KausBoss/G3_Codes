/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head==NULL || head->next==NULL){return head;}
    	ListNode *temp=head->next, *ret=NULL, *prev=head, *n;
    	if(prev->val!=temp->val){ret=prev; ret->next=NULL;}
    	while(temp->next){
    		n=temp->next;
    		if(prev->val!=temp->val && temp->val!=temp->next->val){
    			if(ret){
    				ret->next=temp;
    				ret=ret->next;
    				ret->next=NULL;
    			}
    			else{
    				head=temp;
    				ret=temp;
    				ret->next=NULL;
    			}
    		}
    		prev=temp;
    		temp=n;
    	}
    	if(prev->val!=temp->val){
            if(ret){
    				ret->next=temp;
    				ret=ret->next;
    				ret->next=NULL;
    			}
    			else{
    				head=temp;
    				ret=temp;
    				ret->next=NULL;
    			}
        }
    	return ret?head:ret;
	}
};