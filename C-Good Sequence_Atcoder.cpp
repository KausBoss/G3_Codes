#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	map<ll, ll> m;
	ll n, t, ans=0, num, freq;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t;
		if(m.count(t)){
			m[t]++;
		}
		else{
			m[t]=1;
		}
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		num= it->first;
		freq= it->second;

		if(num>freq){
			ans += freq;
		}
		if(num < freq){
			ans += (freq-num);
		}
	}
	cout<<ans;
}