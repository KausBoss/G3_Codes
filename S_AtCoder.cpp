#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[ 10001 ][ 101 ][ 2 ];
#define mod 1000000007
string s; 

ll func(ll pos, ll d, ll tight){
	//base case
	if(pos == s.length()){
		if(d==0){return 1;}
		return 0;
	}
	//recursive case
	if(dp[pos][d][tight] != -1){return dp[pos][d][tight];}

	ll ans=0;

	ll end = ((tight)?(s[pos]-'0'):9);
	for(ll i = 0; i<=end ;i++){
		ll cntupd = cnt + (i>0);
		if(cntupd<=3){
			ans += Solve(pos+1,cntupd,tight&(i == end));
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	
}