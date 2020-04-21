#include <bits/stdc++.h>

using namespace std;
#define ll signed long int

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll ans = 0, ct=0, a, b, q, f;
		cin>>f>>q;
		for(int i=0; i<q; i++){
			cin>>a>>b;
			ans += abs(ct-a);
			ans += abs(b-a);
			ct=b;
		}
		cout<<ans<<"\n";
	}
}