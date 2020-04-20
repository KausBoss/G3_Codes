#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 200005

int main(){
	ll n, a[inf], num;
	set<ll> s;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num;
		s.insert(num);
		auto it= s.lower_bound(num);
		if(it == s.begin()){
			cout<<-1<<"\n";
		}
		else{
			cout<<*(--it)<<"\n";
		}
	}
}