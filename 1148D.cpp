#include<iostream>
#include<set>
using namespace std;

#define ll long long

int main(){
	set<pair<ll, ll>> asc, dsc;
	ll n, a, b;
	cin>>n;
	for(int i=0; i<n; i++){
			cin>>a>>b;
			if(a>b){
				asc.insert(make_pair(b, i+1));
			}
			else{
				dsc.insert(make_pair(-b, i+1));
			}
	}
	if(asc.size() > dsc.size()){
		cout<<asc.size()<<"\n";
		for(auto x:asc){
			cout<<x.second<<" ";
		}
	}
	else{
		cout<<dsc.size()<<"\n";
		for(auto x:dsc){
			cout<<x.second<<" ";
		}
	}
}