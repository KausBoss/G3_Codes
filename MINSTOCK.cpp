#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
	ll n, cmd, cost, temp;
	string k, name;
	map<string, ll> seedha;
	map<ll, string> ulta;

	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>cmd;
		if(cmd==1){
			cin>>name>>cost;
			seedha[name] = cost;
			ulta[cost] = name;
		}
		if(cmd==2){
			cin>>name>>cost;
			temp = seedha[name];
			seedha[name] = cost;
			ulta.erase(ulta.find(temp));
			ulta[cost] = name;
		}
		if(cmd==3){
			cin>>name;//useless hai ye
			k = ulta.begin()->second;
			ulta.erase(ulta.begin());
			seedha.erase(seedha.find(k));
			cout<<k<<" "<<i+1<<"\n";
		}
	}
}