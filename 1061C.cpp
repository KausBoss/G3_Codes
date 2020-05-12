#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mod = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	ll *a= new ll[n];
	ll *dp= new ll[n+1];
	for(int i=0; i<n; i++){
		cin>>a[i];
		dp[i]=0;
	}
	dp[0]=1;
	dp[n]=0;
	for(int i=0; i<n; i++){
		vector<int> s;
		for(int j=1; j*j<=a[i]; j++){
			if(a[i]%j == 0){
				s.push_back(j);
				if(j!=a[i]/j){
					s.push_back(a[i]/j);
				}
			}
		}
		if(s.size()>0){
			sort(s.begin(), s.end());
			reverse(s.begin(), s.end());
			for(auto it:s){
				if(it <= n){
					dp[it] += dp[it-1];
					dp[it] %= mod;
				}
			}
		}
		s.clear();
	}
	ll ans=0;
	// for(int i=0; i<=n; i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	for(int i=1; i<=n; i++){
		ans+=dp[i];
		ans%=mod;
	}
	cout<<ans;
}