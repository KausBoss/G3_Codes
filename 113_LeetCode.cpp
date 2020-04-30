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
	vector<vector<int>> ans;
	vector<int> temp;
	void fun(TreeNode* root, int sum){
		//base case
		if(root == NULL){
            
			return;
		}
		//recursive case
		temp.push_back(root->val);
        if(sum-root->val==0 && root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
		fun(root->left, sum-root->val);
		fun(root->right, sum-root->val);
		temp.pop_back();
	}
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        fun(root, sum);
        return ans;
    }
};	