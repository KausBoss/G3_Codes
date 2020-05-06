#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define inf (int)1e5
ll n, W, w[100], v[100];
ll dp[100][inf];

ll knapsack(ll i, ll W){
	//base case
	if(i==n || w==0){return 0;}

	//recursive case
	if(dp[i][W]!=-1){return dp[i][W];}

	if(w[i] <= W){
		dp[i][W]= max(v[i]+knapsack(i+1,W-w[i]), knapsack(i+1, W));
	}
	else{
		dp[i][W]=knapsack(i+1, W);
	}
	return dp[i][W];
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof dp);
	cin>>n>>W;
	for(int i=0; i<n; i++){
		cin>>w[i]>>v[i];
	}
	cout<<knapsack(0, W);
}