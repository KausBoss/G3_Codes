#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mod 1000000007

ll power (ll a, ll b){
	a%=mod;
	ll res =1;
	while(b>0){
		if(b%2){
			res *=a;
			res %=mod;
		}
		a *=a;
		a %= mod;
		b /=2;
	}
	return res;
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