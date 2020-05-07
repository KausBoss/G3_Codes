#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m, a;
	cin>>n>>m>>a;
	ll ans = ceil((double)n/a);
	ans *= ceil((double)m/a);
	cout<<ans;
}