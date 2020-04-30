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
#define ll long long
class Solution {
	bool validHai(TreeNode* root, ll min, ll max){
		//base case
		if(root==NULL){
			return true;
		}
		//recursive case
		if((ll)root->val<=min || (ll)root->val>=max){
			return false;
		}
		bool left = validHai(root->left,min, (ll)root->val);
		bool right = validHai(root->right, (ll)root->val, max);
		return left&&right;
	}
public:
    bool isValidBST(TreeNode* root) {
        return validHai(root, LONG_MIN, LONG_MAX);
    }
};