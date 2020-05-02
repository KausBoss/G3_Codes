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
    void func(TreeNode* &root, int i, int v, int d){
        //base case
        if(root==NULL){
            return;
        }
        if(i==d-1){
            TreeNode *l=new TreeNode(v, root->left,NULL);
            TreeNode *r=new TreeNode(v, NULL, root->right);
            root->left=l;
            root->right=r;
            return;
        }
        func(root->left, i+1, v, d);
        func(root->right, i+1, v, d);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode *l=new TreeNode(v, root,NULL);
            return l;
        }
        func(root, 1, v, d);
        return root;
    }
};