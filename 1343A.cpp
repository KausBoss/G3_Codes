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
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll k=2; k<n; k++){
			ll den= pow(2,k) -1;
			if(n%den==0){
				cout<<n/den<<endl;
				break;
			}
		}
	}
}