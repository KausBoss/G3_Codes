#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int *a= new int[5];
	for(int i=0; i<n; i++){cin>>a[i];}

	vector<vector<int>> dp(n-1, vector<int> (n-1, 0));
	for(int c=1; c<n-1; c++){
		int i=0;
		for(int j=c; j<n-1; j++){
			dp[i][j]=INT_MAX;
			for(int k=i; k<j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i]*a[k+1]*a[j+1]);
			}
			i++;
		}
	}
	for(auto x:dp){
		for(auto y:x){
			if(y<10)cout<<" ";
			cout<<y<<" ";
		}
		cout<<endl;
	}
}