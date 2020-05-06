#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define inf (int)1e5

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, a[inf], b[inf], c[inf];
	int dp[inf][3];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i]>>c[i];
		if(i==0){
			dp[0][0]=a[0];
			dp[0][1]=b[0];
			dp[0][2]=c[0];
		}
	}

	for(int i=1; i<n; i++){

		dp[i][0]=a[i] + max(dp[i-1][1],dp[i-1][2]);

		dp[i][1]=b[i] + max(dp[i-1][0],dp[i-1][2]);

		dp[i][2]=c[i] + max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	
}