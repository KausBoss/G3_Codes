#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
ll dp[100005];
ll pre[100005];
ll k;
ll flower(ll len, ll k){
	//base case
	if(len==0){
		return 1;
	}
	//recursive case
	if(dp[len]!=-1){return dp[len];}

	ll op1= flower(len-1, k);
	ll op2= len>=k?flower(len-k, k):0;

	return dp[len]= op1 + op2;
}

void precom(){
	memset(dp, -1, sizeof dp);
	pre[0]=0;
	for(int i=1; i<100000; i++){
		pre[i]=pre[i-1] + flower(i, k);
		pre[i] %= mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t>>k;
	precom();
	while(t--){
		ll a, b;
		cin>>a>>b;
		cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
	}
	
}