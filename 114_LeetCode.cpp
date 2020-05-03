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
	TreeNode* LL(TreeNode* &root){
		//base case
		if(root==NULL){return NULL;}
		if(root->left==NULL){
			root->right=LL(root->right);
			return root;
		}
		//recursive case
		root->left = LL(root->left);
		root->right= LL(root->right);
		TreeNode* n=root->left;
		while(n->right){
			n=n->right;
		}
		n->right=root->right;
		root->right=root->left;
		root->left=NULL;
		return root;

	}
    void flatten(TreeNode* root) {
        LL(root);
    }
};