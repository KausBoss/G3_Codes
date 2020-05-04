class Solution {
        int stair(vector<int> cost, int i, vector<int> &dp){
        	//base case
        	if(i>=cost.size()){
        		return 0;
        	}
        	//base case
        	if(dp[i]!=-1){return dp[i];}
        	int op1=stair(cost,i+1, dp) + cost[i];
        	int op2=stair(cost,i+2, dp) + cost[i];

        	dp[i]= min(op1,op2);

        	return min(op1,op2);

        }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        int op1=stair(cost, 0, dp);
        int op2=stair(cost, 1,dp);

        return min(op1,op2);
    }
};