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
	pair<int,int> MX(TreeNode* root){
		//base case
		if(root==NULL){
			return make_pair(0,INT_MIN);
		}
		//recursive case
		pair<int,int> p;
		pair<int,int> left = MX(root->left);
		pair<int,int> right = MX(root->right);
		int d=root->data;
		int mxrn=max(left.second, max(right.second, d));	
		p.second=msrn;
		if(d+left.first<0 &&d+right.first<0){
			p.first=0;
			return p;
		}
		if(d+left.first+right.first>msrn){
			p.second=d+left.first+right.first;
		}
		p.first = max(left.first, right.first) +d;
		return p;
	}
    int maxPathSum(TreeNode* root) {
        return MX(root).second;
    }
};