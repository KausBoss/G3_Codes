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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	ListNode* middy(ListNode* head){
		ListNode *slow=head;
		ListNode *fast=head->next;
		ListNode *prev=NULL;
		while(fast && fast->next){
			prev=slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		return prev;
	}
	TreeNode* make(ListNode* head){
		//base case
		if(head==NULL){
			return NULL;
		}
		//recursive case
		if(head->next==NULL){
			TreeNode *n= new TreeNode(head->val);
			return n;
		}
		ListNode *mid=middy(head);
		if(mid==NULL){
			TreeNode *n = new TreeNode(head->val,NULL, make(head->next));
			return n;
		}
		ListNode *b=mid->next;
		mid->next=NULL;
		TreeNode *n= new TreeNode(b->val, make(head),make(b->next));
		return n;
	}
    TreeNode* sortedListToBST(ListNode* head) {
        return make(head);
    }
};