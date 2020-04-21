#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll a, ll b){
	//base case
	if(b == 0){
		return 1;
	}
	//recursive case
	ll s= power(a, b/2);
	s %= mod;
	s *= s; 
	s %=mod;
	return b%2? (s*a)%mod: s;
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t, n, a;
	cin>>t;
	while(t--){
		cin>>n>>a;
		ll p, ans=0;
		for(int i=1; i<=n; i++){
			p = power(a, (2*i-1));
			a *= p;
			a %= mod;
			ans += p;
			ans %=mod;
		}
		cout<<ans<<endl;
	}
}