#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n, prev=0, ans=1;
		cin>>n;
		int ar[n], ct = 0;
		for(int i=0; i<n; i++){
			cin>>ar[i];
		}

		for(int i=0; i<n-1; i++){
			if((ar[i]&ar[i+1]) != ar[i]){
				cout<<0<<endl;
				ct = 1;
				break;
			}
		}
		if(ct == 0){
			for(int i=0; i<n-1; i++){
				prev += __builtin_popcount(ar[i]);
			}
			while(prev--){
			 	ans = (ans*2)%mod;
			}
			cout<<ans<<endl;
		}
	}
}