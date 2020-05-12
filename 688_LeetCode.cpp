//https://leetcode.com/problems/knight-probability-in-chessboard/submissions/
class Solution {
public:
	double dp[25][25][101];
	Solution(){
		memset(dp, -1, sizeof(dp));
	}
    double knightProbability(int N, int K, int r, int c) {
        //base case
        if(K==0){
        	return 1;
        }
        //recursive case
        if(dp[r][c][K]>-1){return dp[r][c][K];}

        double ans=0;
        if(r-2>=0){
        	if(c+1<N){
        		ans += knightProbability(N, K-1, r-2, c+1)/8;
        	}
        	if(c-1>=0){
        		ans += knightProbability(N, K-1, r-2, c-1)/8;
        	}
        }
        if(r+2<N){
        	if(c+1<N){
        		ans += knightProbability(N, K-1, r+2, c+1)/8;
        	}
        	if(c-1>=0){
        		ans += knightProbability(N, K-1, r+2, c-1)/8;
        	}
        }
        if(c-2>=0){
        	if(r+1<N){
        		ans+= knightProbability(N, K-1, r+1, c-2)/8;
        	}
        	if(r-1>=0){
        		ans+= knightProbability(N, K-1, r-1, c-2)/8;
        	}
        }
        if(c+2<N){
        	if(r+1<N){
        		ans+= knightProbability(N, K-1, r+1, c+2)/8;
        	}
        	if(r-1>=0){
        		ans+= knightProbability(N, K-1, r-1, c+2)/8;
        	}
        }
        return dp[r][c][K] = ans;
    }
};