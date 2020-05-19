#include <bits/stdc++.h>

using namespace std;
#define ll long long

 int longestValidParentheses(string s) {
    int cnt = 0; // count of "("
    vector<int> dp(s.size()+1, 0);
    
    for (size_t i = 1; i <= s.size(); i++) {
        if (s[i-1] == '(') {
            cnt++;
        } else {
            if (cnt > 0) {  // there exists an unclosed "(" to match ")"
                cnt--;
                dp[i] = 2;
                if (s[i-2] == ')')  // add the length of previous closed ")" neighbor
                    dp[i] += dp[i-1];                        
                dp[i] += dp[i-dp[i]]; // add the length of previous valid parentheses
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s=")()())";
	cout<<longestValidParentheses(s);
}
