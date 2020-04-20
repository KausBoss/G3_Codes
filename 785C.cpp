#include <iostream>

using namespace std;
#define ll long long

ll val(ll x){
	x *=(x+1);
	x /=2;
	return x;
}

int main(){
	ll n, m, mid, s, e;
	cin>>n>>m;
	if(m>=n){
		cout<<n;
		return 0;
	}
	s=0;
	e=1e10;
	while(s<=e){
		mid = (s+e)/2;
		if(val(mid)>=(n-m) && val(mid-1)<(n-m)){
			cout<<mid+m;
			return 0;
		}
		if(val(mid)>=(n-m)){
			e=mid-1;
		}
		if(val(mid)<(n-m)){
			s=mid+1;
		}
	}
}
