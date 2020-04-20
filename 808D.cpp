#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

#define ll long long

int main(){
	ll n, a[100000], sum, tsum=0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum%2){cout<<"NO"; return 0;}

	sum /=2;

	map <ll,int> mp;
	for(int i=0; i<n; i++){
		mp.insert(make_pair(a[i],1));
		tsum+=a[i];
		ll diff = tsum -sum;
		if(mp.count(diff)==1){
			cout<<"YES";
			return 0;
		}
	}

	tsum=0;
	mp.clear();
	for(int i=n-1; i>=0; i--){
		tsum += a[i];
		mp.insert(make_pair(a[i], 1));
		ll diff= tsum - sum;
		if(mp.count(diff)==1){ 
			cout<<"YES"; 
			return 0;
		}
	}
	cout<<"NO";
	
}