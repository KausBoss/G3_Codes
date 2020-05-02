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
//bhai DP lagadi
class Solution {
	map<pair<TreeNode*,bool>,int> m;
	int func(TreeNode* root, bool kia){
		//base case
		if(root==NULL){
			return 0;
		}
		//recursive case
		if(m.count(make_pair(root,kia))){
			return m[make_pair(root,kia)];
		}
		if(kia){
			m[make_pair(root,kia)]=(func(root->left,0)+func(root->right,0));
			return (func(root->left,0)+func(root->right,0));
		}
		else{
			int a1=(func(root->left,0)+func(root->right,0));
			int a2=root->val + func(root->left,1)+func(root->right,1);
			m[make_pair(root,kia)]=max(a1,a2);
			return max(a1,a2);
		}
	}
public:
    int rob(TreeNode* root) {
        return func(root,0);
    }
};