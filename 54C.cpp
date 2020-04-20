#include <bits/stdc++.h>

using namespace std;
#define ll long long

class dance{
public:
	ll id;
	ll diff;
	dance(ll id, ll diff){
		this->id=id;
		this->diff=diff;
	}
};

struct comp{
	bool operator()(dance a, dance b){
		return a.diff < b.diff;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, gno=0, bno=0;	
	priority_queue<dance, vector<dance>, comp> p;	
	string s;
	vector<ll> ability;
	cin>>n;
	cin>>s;
	for(int i=0; i<n; i++){
		if(s[i]=='G'){gno++;}
		else{bno++;}
	}
	for(int i=0; i<n; i++){
		ll temp;
		cin>>temp;
		ability.push_back(temp);
	}
	for(int i=0; i<n-1; i++){
		if(s[i]!=s[i+1]){
			ll diff= abs(ability[i]-ability[i+1]);
			dance d(i, diff);
			p.push(d);
		}
	}
	cout<<min(bno, gno);
}