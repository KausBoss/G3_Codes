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
	int ct=0;
	pair<bool, bool> func(TreeNode* root){
		//base case
		if(root==NULL){
			return make_pair(true, false);
		}
		//recursive case
		pair<bool,bool> left = func(root->left);
		pair<bool, bool> right= func(root->right);
		pair<bool, bool> p;
		if(!left.first || !right.first){
			ct++;
			return make_pair(true, true);
		}
		if(left.second || right.second){
			return make_pair(true, false);
		}
		return make_pair(false, false);
	}
public:
    int minCameraCover(TreeNode* root) {
        pair<bool, bool> at =func(root);
        if(at.first){return ct;}
        else{return ct+1;}
    }
};