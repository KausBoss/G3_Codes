#include <bits/stdc++.h>

using namespace std;
#define ll long long
pair<ll,string> dp[19][2][2][2];
string a, b;

pair<ll, string> solve(ll pos, bool ta, bool tb, bool st){
	//base case
	if(pos == a.length()){
		return {1, ""};
	}
	//recursive case
	if(dp[pos][ta][tb][st].first!=-1){return dp[pos][ta][tb][st];}
	ll lb = ta?a[pos]-'0':0;
	ll ub = tb?b[pos]-'0':9;
	pair<ll,string> ans(-1, "");
	for(ll i=lb; i<=ub; i++){
		ll val = (st==0&&i==0)?1:i;
		auto ret = solve(pos+1, ta&(i==lb), tb&(i==ub), st|(i>0));
		if(val*ret.first > ans.first){
			ans.first = val*ret.first;
			ans.second = (st==0&&i==0)? ret.second: to_string(val)+ ret.second;
		}
	}
	return dp[pos][ta][tb][st]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	for(int i=0; i<19; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				for(int l=0; l<2; l++){
					dp[i][j][k][l].first=-1;
				}
			}
		}
	}
	cin>>a;
	cin>>b;
	// cout<<a.length()<<" "<<b.length();
	while(b.length()>a.length()){
		a  = '0' + a;
	}
	//cout<<a<<endl<<b<<endl;
	cout<<solve(0, 1,1, 0).second;
}