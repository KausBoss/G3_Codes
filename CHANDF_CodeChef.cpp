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
	int t;
	cin>>t;
	while(t--){
		ll x, y, l, r;
		cin>>x>>y>>l>>r;
		ll bit=0;
		ll up= log2(r);
		cout<<x<<" "<<y<<" "<<l<<" "<<r<<" thats it"<<endl;
		for(ll i=0; i<up;i++){
			//cout<<bit<<" ";
			ll a = 1<<i;
			cout<<i<<"  "<<(x&a)<<"  "<<(y&a)<<" bit is: "<<bit<<endl;
			if((x&a)>0 || (y&a)>0){
				if((bit|a) > r){break;}
				bit = bit|a;
			}
		}
		cout<<bit<<endl;
	}
}