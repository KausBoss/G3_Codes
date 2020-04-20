#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
	int n, a, b, k, f;
	string x, y, prev="";
	map<string, int> m;

	cin>>n>>a>>b>>k>>f;

	for(int i=0; i<n; i++){
		cin>>x>>y;
		int cost= prev==x? b:a;
		prev = y;
		if(x>y){
			swap(x,y);
		}
		if(m.count(x+y)){
			m[x+y] += cost;
		}
		else{
			m[x+y] = cost;
		}
	}
	multiset<int, greater<int>> s;
	int ans=0;
	for( auto it=m.begin(); it!=m.end(); it++){
		s.insert(it->second);
	}
	for(auto it=s.begin(); it!=s.end(); it++){
		if(k>0 && *it>f){
			ans += f;
			k--;
		}
		else{
			ans += *it;
		}
	}
	cout<<ans;
}	