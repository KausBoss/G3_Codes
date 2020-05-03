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
	int ans=0;
	int func(TreeNode* root){
		//base case
		if(root==NULL){
			return NULL;
		}
		//recursive case
		int left = abs(func(root->left));
		int right=abs(func(root->right));
		ans += left+right
		return (root->val-1)+left+right;
	}
    int distributeCoins(TreeNode* root) {
    	 func(root);
    	 return ans;
    }
};