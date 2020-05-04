class Solution {
public:
	int dp[101][101];
	int Path(int i, int j){
		//base case
		if(i==1 && j==1){return 1;}
		if(i<1 || j<0){
			return 0;
		}
		//recursive case
		if(dp[i][j]!=-1){return dp[i][j];}
		dp[i][j]= Path(i-1,j) + Path(i, j-1);
		return dp[i][j];
	}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return Path(m,n);
    }
};