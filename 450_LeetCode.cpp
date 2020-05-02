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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==NULL){
        	return NULL;
        }
        //recursive case
        if(root->val > key){
        	root->left = deleteNode(root->left, key);
        	return root;
        }
        if(root->val == key){
        	//root with no children
        	if(root->left==NULL && root->right==NULL){
        		delete root;
        		return NULL;
        	}
        	//root has only one child
        	if(root->left!=NULL && root->right==NULL){
        		TreeNode* temp = root->left;
        		delete root;
        		return temp;
        	}
        	if(root->left==NULL && root->right!=NULL){
        		TreeNode* temp = root->right;
        		delete root;
        		return temp;
        	}
        	//root has both children
        	if(root->left!=NULL && root->right!=NULL){
        		TreeNode* rep=root->right;
        		while(rep->left!=NULL){
        			rep=rep->left;
        		}
        		root->val = rep->val;
        		root->right = deleteNode(root->right, rep->val);
        		return root;
        	}
        }
        if(root->val < key){
        	root->right = deleteNode(root->right, key);
        	return root;
        }
        return NULL;
    }
};