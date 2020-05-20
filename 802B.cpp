#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, s;
	cin>>n>>s;
	int *a = new int[n];
	unordered_map<int, int> m;
	map<int, set<int>> id;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(id.count(a[i])==0){
			id[a[i]].insert(INT_MAX);
		}
		id[a[i]].insert(i);
	}
	int ans=0;
	for(int i=0; i<n; i++){
		if(m.count(a[i])==0){
			ans++;
			if(m.size() == s){
				int rem, pos=-1;
				for(auto x:m){
					if(x.second > pos){
						rem = x.first;
						pos = x.second;
					}
				}
				m.erase(rem);
			}
			m[a[i]] = *(id[a[i]].upper_bound(i));
		}
	}
	cout<<ans;
}