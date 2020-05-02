#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool sorty(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return a.first>b.first;
	}
	return a.second<b.second;
}

// bool sorty(pair<int, int> a, pair<int, int> b){
// 	 if(a.second==b.second)
//         return a.first < b.first; //Max Heap (Descending)
//     else
//         return a.second < b.second; //Min Heap (Ascending)
// }



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<pair<int, int>> v;
	int n;
	cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end(), sorty);
	for(auto x:v){
		cout<<x.first<<" "<<x.second<<endl;
	}
}

// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]