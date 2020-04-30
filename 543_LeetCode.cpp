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
	pair<int, int> dia(TreeNode* root){
		//base case
		if(root==NULL){
			return make_pair(0,0);
		}
		//recursive case
		pair<int, int> left = dia(root->left);
		pair<int, int> right= dia(root->right);
		pair<int, int> p;
		int  dia_here= left.second + right.second ;
		p.second = max(left.second, right.second) +1;
		p.first = max(dia_here, max(left.first, right.first));
		return p;
	}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).first;
    }
};