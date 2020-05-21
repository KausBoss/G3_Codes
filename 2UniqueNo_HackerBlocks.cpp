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
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &x:v){
		cin>>x;
	}
	int xr=0;
	for(auto x: v){
		xr ^=x;
	}
	xr &=-xr;
	int x1=0, x2=0;
	for(auto x:v){
		if(x&xr){
			x1 ^= x;
		}
		else{
			x2 ^= x;
		}
	}
	if(x1 > x2){ swap(x1, x2);}

	cout<<x1<<" "<<x2;
}