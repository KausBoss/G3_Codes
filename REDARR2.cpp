#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
	int t;
	ll n, temp, ans;
	priority_queue<ll> p;
	cin>>t;
	while(t--){
		ans=0;
		p = priority_queue<ll> ();
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>temp;
			p.push(-temp);
		}
		while(p.size()>1){
			//cout<<p.top()<<"*";
			temp = p.top();
			p.pop();
			//cout<<p.top()<<"&";
			temp += p.top();
			p.pop();
			ans += temp;
			p.push(temp);
			//cout<<temp<<"--";
		}
		cout<<-ans<<"\n";
	}
}