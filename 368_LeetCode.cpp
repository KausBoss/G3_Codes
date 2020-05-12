//https://leetcode.com/problems/largest-divisible-subset/submissions/
class Solution {
public:
	unordered_map<int, vector<int>> h;

	vector<int> FindAll(int i,vector<int>n){
		//base case
		if(h.count(i)){return h[i];}

		vector<int> ans;
		for(int j=0; j<i; j++){
			if(n[i]%n[j]==0){
				auto x=FindAll(j, n);
				if(x.size() > ans.size()){
					ans=x;
				}
			}
		}
		ans.push_back(n[i]);
		return h[i]=ans;
	}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
        	auto x= FindAll(i, nums);
        	if(x.size()>ans.size()){
        		ans = x;
        	}
        }
        return ans;
    }
};