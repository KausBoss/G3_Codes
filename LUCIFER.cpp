#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[10][91][2];
string s;
map<ll,ll> m;

ll lucifer(ll i, ll sum, bool tight){
	//base case
	if(i == s.length()){
		if(s.length()%2==0){sum*=-1;}
		return m.count(sum);
	}
	//recursive case
	if(dp[i][sum+45][tight]!=-1){ return dp[i][sum+45][tight]; }

	ll end = tight?s[i]-'0':9;
	ll ans=0;
	for (ll j=0; j<=end; j++){
		ll adder = (i%2)?j:-j;
		ans += lucifer(i+1, sum + adder, (tight)&(j==end));
	}
	return dp[i][sum+45][tight] = ans;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> p{2,3,5,7,11,13,17,19,23,29,31,37,43};
	for(auto x:p){
		m[x]=x;
	}
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		memset(dp, -1, sizeof(dp));
		s = to_string(b);
		ll ans = lucifer(0, 0, 1);

		a--;
		memset(dp, -1, sizeof(dp));
		s = to_string(a);
		ans -= lucifer(0, 0, 1);
		cout<<ans<<endl;
	}
}