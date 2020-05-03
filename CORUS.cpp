#include <bits/stdc++.h>

using namespace std;
#define ll long long

void funk(vector<ll> freq, ll n, ll c){
	ll total=0;
	for(ll i=0; i<26; i++){
		if(freq[i]>=c){
			freq[i] -=c;
		}
		else{
			freq[i]=0;
		}
		total += freq[i];
	}
	cout<<total<<"\n";
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
		ll n, q, c;
		vector<ll> freq(26,0);
		string s;
		cin>>n>>q;
		cin>>s;
		for(auto x:s){
			freq[x-'a']++;
		}
		while(q--){
			cin>>c;
			funk(freq, n, c);
		}
	}
}