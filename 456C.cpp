#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
#define inf (ll)1e5
ll n, a[inf];
map<pair<ll,ll>, ll> m;

ll total(ll freq[], ll i){
	//base case
	if(i == n){
		return 0;
	}
	//recursive case
	if(m.count(make_pair(a[i], freq[a[i]]))){return m[make_pair(a[i], freq[a[i]])];}

	ll op1 = total(freq, i+1);
	ll up=freq[a[i]+1];
	ll low=freq[a[i]-1];
	freq[a[i]+1]=0;
	freq[a[i]-1]=0;
	ll op2 = (a[i]*freq[a[i]]) + total(freq, i+1);
	m[make_pair(a[i], freq[a[i]])]= max(op1, op2);
	//cout<<a[i]<<" "<<freq[a[i]]<<" "<<max(op1, op2)<<endl;

	freq[a[i]+1]=up;
	freq[a[i]-1]=low;

	return max(op1,op2);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll temp, freq[inf+5]={0};
	set<ll> s;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>temp;
		freq[temp]++;
		s.insert(temp);
	}
	ll i=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		a[i++]=*it;
	}
	n=s.size();
	cout<<total(freq, 0);
}