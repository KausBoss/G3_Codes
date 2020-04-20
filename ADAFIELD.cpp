#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n, m, q;
		cin>>n>>m>>q;
		multiset<ll> x, y, segx, segy;
		x.insert(0); y.insert(0);
		x.insert(n); y.insert(m);
		segx.insert(n); segy.insert(m);

		for(int i=0; i<q; i++){
			ll about, alpha;
			cin>>about>>alpha;
			if(about==0){
				//change in x
				if(x.find(alpha)!=x.end()){
					cout<<*(--segx.end())**(--segy.end())<<"\n";
					continue;
				}
				auto low= x.lower_bound(alpha);
				low--;//important kyunki neeche waali value chahiye
				auto high=x.upper_bound(alpha);
				x.insert(alpha);
				segx.erase(segx.find(*high - *low));
				segx.insert(*high - alpha);
				segx.insert(alpha - *low);
			}
			else{
				//change in y
				if(y.find(alpha)!=y.end()){
					cout<<*(--segx.end())**(--segy.end())<<"\n";
					continue;
				}
				auto low= y.lower_bound(alpha);
				low--;
				auto high=y.upper_bound(alpha);
				y.insert(alpha);
				segy.erase(segy.find(*high - *low));
				segy.insert(*high - alpha);
				segy.insert(alpha - *low);
			}
			cout<<*(--segx.end())**(--segy.end())<<"\n";
		} 
	}
}