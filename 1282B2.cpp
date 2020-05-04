#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n, p, k,a[200001];

ll func(){
	sort(a, a+n+1);
	ll dp[200001]={0};
	a[0]=0;
	ll ans=0;
	for(ll i=1;i<=n; i++){
		if(i<k){
			dp[i] = a[i] + dp[i-1];
		}
		else if(i == k){
			dp[i] = a[i];
		}
		else{
			dp[i]=a[i] + dp[i-k];
		}
		if(dp[i] <= p){ans=i;}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		cout<<func()<<endl;
	}
}