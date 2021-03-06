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
	string s="";
	void para(TreeNode* t){
		//base case
		if(t==NULL){
			return;
		}
		//recursive case
		s += to_string(t->val);
		if(t->left){
			s+='(';
			para(t->left);
			s+=')';
		}
		if(t->right){
			if(!t->left){s+="()";}
			s+='(';
			para(t->right);
			s+=')';
		}
		return;
	} 
    string tree2str(TreeNode* t){
        para(t);
        return s;
    }
};