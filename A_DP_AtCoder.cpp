#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, h[100000], dp[100000];

int cost(int i){
	//base case
	if(i>= n-1){
		return 0;
	}
	//recursive case
	if(dp[i]!=-1){return dp[i];}

	int op1 = abs(h[i]-h[i+1]) + cost(i+1);
	int op2 = (i!=n-2)?abs(h[i]-h[i+2]) + cost(i+2):INT_MAX;

	dp[i]=min(op1, op2);
	return dp[i];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>h[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<cost(0);
}