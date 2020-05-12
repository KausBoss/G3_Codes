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
	ll n, q, *a, *x, *y;
	cin>>n>>q;
	a = new ll[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<q; i++){
		cin>>x[i]>>y[i];
	}
	
}