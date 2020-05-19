#include <bits/stdc++.h>

using namespace std;
#define ll long long

void printy(vector<vector<int>> dp){
	for(auto x:dp){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n\n";
	return;
}

int maxCoins(vector<int> A) {
	if(A.empty()) return 0;
    int n=A.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int L=n-1; L>=0; L--){
    	for(int R=L; R<n; R++){
    		for(int i=L; i<=R; i++){
        		dp[L][R] = max(dp[L][R],
        				   A[i]*(L?A[L-1]:1)*(R==n-1?1:A[R+1])
        				   + (L<=i-1?dp[L][i-1]:0) + (i+1<=R?dp[i+1][R]:0)
        			);
        	}
        	printy(dp);
    	}
    }
    // for(int i=0; i<n; i++){
    // 	for(int j=0; j<n; j++){
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    return dp[0][n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<maxCoins({3,1,5,8});
}
