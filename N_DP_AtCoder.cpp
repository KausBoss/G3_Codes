//https://atcoder.jp/contests/dp/tasks/dp_n
#include <bits/stdc++.h>

using namespace std;
#define ll signed long long int

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	ll *a=new ll[n];
	ll *pre=new ll[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
		if(i==0){
			pre[i]=a[i];
		}
		else{
			pre[i]=a[i]+pre[i-1];
		}
	}

	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for(ll c=1; c<n; c++){
		ll i=0;
		for(ll j=c; j<n; j++){
			dp[i][j]=1e13;
			for(ll k=i; k<j; k++){
				ll part1 = i!=0?pre[k]-pre[i-1]:pre[k];
				ll part2 = pre[j]-pre[k];
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + part1+part2);
			}
			i++;
		}
	}
	// for(auto x:dp){
	// 	for(auto y:x){
	// 		if(y<10)cout<<" ";
	// 		cout<<y<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[0][n-1];
}