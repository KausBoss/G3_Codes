#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<int> rearrangeBarcodes(vector<int> barcodes) {
	map<int, int> m;
	priority_queue<pair<int, int>> p;
	vector<int> ans(barcodes.size());
	for(auto x:barcodes){
		if(m.count(x)){m[x]++;}
		else{m[x]=1;}
	}
	for(auto x:m){
		p.push(make_pair(x.second, x.first));
	}
	int freq=p.top().first;
	for(int i=0; i<barcodes.size(); i+=2){
		if(freq){
			ans[i]=p.top().second;
			freq--;
		}
		else{
			p.pop();
			freq=p.top().first;
			ans[i]=p.top().second;
			freq--;
		}
	}
	for(int i=1; i<barcodes.size(); i+=2){
		if(freq){
			ans[i]=p.top().second;
			freq--;
		}
		else{
			p.pop();
			freq=p.top().first;
			ans[i]=p.top().second;
			freq--;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{2,2,2,1,5};
	v = rearrangeBarcodes(v);
	for(auto x:v){
		cout<<x<<" ";
	}
}