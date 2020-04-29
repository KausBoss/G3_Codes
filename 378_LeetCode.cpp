class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> p;
        for(auto x:matrix){
        	for(auto y:x){
        		p.push(y);
        		if(p.size() > k){
        			p.pop();
        		}
        	}
        }
        return p.top();
    }
};