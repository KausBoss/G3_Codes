/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	pair<TreeNode*, bool> func(TreeNode* root, TreeNode* p, TreeNode* q){
		pair<TreeNode*,bool> n;
		n.first=NULL;
        //base case
		if(root==NULL){
            n.second=false;
			return n;
		}
		//recursive case
		
		pair<TreeNode*,bool> left = func(root->left, p, q);
		pair<TreeNode*,bool> right= func(root->right, p,q);
		if(root==p || root==q){
			n.second=true;
			if(left.second || right.second){
				n.first=root;
			}
			return n;
		}
		if(left.first){return left;}
		if(right.first){return right;;}
		if(left.second && right.second){
			n.first=root;
			n.second=true;
			return n;
		}
		n.second = left.second||right.second;
		return n;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root, p, q).first;
    }
};