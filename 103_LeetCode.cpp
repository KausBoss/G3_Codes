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
	vector<vector<int>> ans;
	void BFS(TreeNode* root){
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		bool dir=false;
		vector<int> temp;
		while(!q.empty()){
			if(q.front()==NULL){
				q.pop();
				if(dir){
					reverse(temp.begin(),temp.end());
					dir=false;
				}
				else{dir=true;}
				ans.push_back(temp);
				temp.clear();
				if(!q.empty()){q.push(NULL);}
			}
			else{
				TreeNode* n=q.front();
				q.pop();
				temp.push_back(n->val);
				if(n->left){
					q.push(n->left);
				}
				if(n->right){
					q.push(n->right);
				}
			}
		}
	}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        BFS(root);
        return ans;
    }
};