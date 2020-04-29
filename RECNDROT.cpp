#include <bits/stdc++.h>

using namespace std;
#define ll long long

void func(){
	map<ll, ll> m;
	map<ll, ll> mini;
	ll n, ans=0;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0; i<n; i++){
		cin>>v[i];
		m[v[i]]=i;
		if(mini.count(v[i])==0){mini[v[i]]=i;}
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		auto c= it;
		c++;
		ll sm = mini[it->first];
		if(c==m.end()){break;}
		if(sm > c->second){
			ans++;
		}
	}
	cout<<ans+1<<"\n";
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
		func();
	}
}