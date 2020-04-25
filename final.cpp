#include <bits/stdc++.h>

using namespace std;
#define ll long long int

bool func(pair<ll, ll> a, pair<ll, ll> b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	else{
		return a.first < b.first;
	}
}

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
		ll k, n, temp;
		cin>>n>>k;
		ll flag=3;
		vector<pair<ll,ll> > v(n);
		for(int i=0; i<n; i++){
			cin>>temp;
			ll pos=i%k;
			v[i]=make_pair(temp,pos);
		}
		if(k==1){cout<<"yes\n"; continue;}
		sort(v.begin(), v.end(), func);
		ll anti[100001];
		ll kt=0;
		for(int i=0; i<k; i++){
			for(int j=0; (i+j)<n; j+=k){
				anti[i+j]=v[kt++].first;
			}
		}
		//for(int i=0; i<n; i++){cout<<anti[i]<<" ==";}
		for(int i=0; i<n-1; i++){
			if(anti[i] > anti[i+1]){
				cout<<"no\n";
				flag=12;
				break;
			}
		}
		if(flag==3){cout<<"yes\n";}
	}
}