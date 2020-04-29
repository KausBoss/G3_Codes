#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> p;
    for(auto x:nums){
    	if(m.count(x)){m[x]++;}
    	else{m[x]=1;}
    }
    for(auto x:m){
    	p.push(x);
    	if(p.size() > k){
    		p.pop();
    	}
    }
    vector<int> ans;
    while(!p.empty()){
    	ans.push_back(p.top().second);
        p.pop();
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
	vector<int> v{-1, -1};
}