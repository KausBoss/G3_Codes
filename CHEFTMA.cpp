#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool func(ll a,ll b){
	return a>b;
}

int main(){
	ll t, temp, n, k, m, ans=0;
	vector <ll> v, s;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>k>>m;
		for(ll i=0; i<n; i++){
			cin>>temp;
			v.push_back(temp);
		}

		for(ll i=0; i<n; i++){
			cin>>temp;
			v[i] -= temp;
		}

		for(ll i=0; i<(k+m); i++){
			cin>>temp;
			s.push_back(temp);
		}
		sort(v.begin(), v.end(), func);
		sort(s.begin(), s.end(), func);

		ll i=0, j=0;
		while(i<n && j<(k+m)){
			if(v[i] < s[j]){
				j++;
			}
			else if(v[i] >= s[j]){
				v[i++] -= s[j++];
			}
		}

		ll ans=0;
		for(int i=0;i<n; i++){ans+= v[i];}

		cout<<ans<<endl;
		v.clear(); s.clear();
	}
}