#include <bits/stdc++.h>

using namespace std;
#define ll long long


int superEggDrop(int K, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    int m = 0;
    while (dp[m][K] < N) {
        m++;
        for (int k = 1; k <= K; ++k)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    for(int i=0; i<=N; i++){
    	for(int j=0; j<=K; j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return m;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<superEggDrop(3, 6);
}
