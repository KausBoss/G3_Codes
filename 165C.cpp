#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll sum[10000005]={0};
ll k;
string a;

void 	 solve(){
	ll s=0;
	ll ans=0;
	sum[0]=1;
	for(int i=0; i<a.length(); i++){
		s += a[i]-'0';
		if(s>=k){
			ans += sum[s-k];
		}
		sum[s]++;
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>k;
	cin>>a;
	solve();
	return 0;
}

