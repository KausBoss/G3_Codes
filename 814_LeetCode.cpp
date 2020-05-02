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
	bool kato(TreeNode* &root){
		//base  case
		if(root==NULL){
			return false;
		}
		//recursive case
		bool left = kato(root->left);
		bool right = kato(root->right);
		if(!left){
			root->left=NULL;
		}
		if(!right){
			root->right=NULL;
		}
		return left || right || root->val;
	}
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool x= kato(root);
        if(!x){return NULL;}
        return root;
    }
};