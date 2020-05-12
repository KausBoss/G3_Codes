//https://leetcode.com/problems/wildcard-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
    	s = ' '+s;
    	p = ' '+p;
    	int ps=p.size();
    	int ss=s.size();
    	vector<vector<bool>> dp(ps, vector<bool>(ss, 0));
    	dp[0][0]=1;
        
        for(int i = 1;i<ps;i++){
            if(p[i] == '*')
                dp[i][0] = (true&&dp[i-1][0]);
        }
    	for(int i=1; i<ps; i++){
    		int j = 1;
			if(p[i] == '*'){
				while(j<ss){
					if(dp[i-1][j-1] || dp[i-1][j]){
						while(j<ss){
							dp[i][j++] = true;	
						}
					}
					j++;
				}
			}
			else if(p[i] == '?'){
				while(j<ss){
					dp[i][j] = dp[i-1][j-1];
					j++;
				}
			}
			else{
				while(j<ss){
					if(s[j] == p[i]){
						dp[i][j] = (true&&dp[i-1][j-1]);
					}
					j++;
				}
			}
    	}
    	return dp[ps-1][ss-1];
    }
};