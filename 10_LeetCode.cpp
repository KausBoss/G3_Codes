#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isMatch(string s, string p) {
    s = ' '+s;
    p = ' '+p;
    int ps=p.size();
    int ss=s.size();
    vector<vector<bool>> dp(ps, vector<bool>(ss, false));
    dp[0][0]=1;
    for(int i=1; i<ps; i++){
    	dp[i][0] = (p[i]=='*')?dp[i-2][0]:dp[i][0];
    }

    for(int i=1; i<ps; i++){
    	for(int j=1; j<ss; j++){
    		if(p[i]==s[j] || p[i]=='.'){
    			dp[i][j]=dp[i-1][j-1];
    		}
    		else if(p[i]=='*'){
    			dp[i][j]=dp[i-2][j];
    			if(p[i-2]=='.' || p[i-2]==s[i]){
    				dp[i][j]=dp[i][j]|dp[i][j-1];
    			}
    		}
    		else{

    		}
    	}
    }

    for(int i=0; i<ps; i++){
    	cout<<p[i]<<" ";
    	for(int j=0; j<ss; j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return dp[ps-1][ss-1];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string s= "mississippi";
    string p= "mis*is*p*.";
    cout<<"    ";
    for(auto x:s){
    	cout<<x<<" ";
    }
	cout<<endl<<isMatch(s, p);
}

