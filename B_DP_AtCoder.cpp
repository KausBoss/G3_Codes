#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, k, h[100000], dp[100000];

int cost(int i){
	//base case
	if(i>= n-1){
		return 0;
	}
	//recursive case
	if(dp[i]!=-1){return dp[i];}

	int ans=INT_MAX;

	for(int j=1; j<=k&&i+j<n; j++){
		ans = min(ans, abs(h[i]-h[i+j]) + cost(i+j));
	}

	dp[i]=ans;
	return dp[i];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>h[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<cost(0);
}