#include <bits/stdc++.h>

using namespace std;
#define ll long long int

vector<ll> prime;

void MakeSieve(){
	const int n = 100000;
	bitset<n> pr;
	for(int i=3;i*i<=n;i+=2){
		if(!pr[i]){
			for(int j=i*i; j<=n; j+=2*i){
				pr[j]=1;
			}
		}
	}
	prime.push_back(2);
	for(int i=3; i<=n; i++){
		if(!pr[i]){
			prime.push_back(i);
		}
	}
}

void SegmentSieve(ll a, ll b){
	bool seg[b-a+1];
	memset(seg, false, sizeof(seg));
	for(int i=0; prime[i]*prime[i]<=b; i++){
		ll n= prime[i];
		ll start = (a/n)*n;
		if(start < a){start += n;}
		ll end = (b/n)*n;
		for(int j=start; j<=end; j+=n){
			if(j!=n){
				seg[j-a]=true;
			}
		}
	}

	for(int i=a; i<=b; i++){
		if(!seg[i-a]){
			cout<<i<<"\n";
		}
	}
}

int main(){	
	MakeSieve();
	ll t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==1){a++;}
		SegmentSieve(a, b);
		cout<<'\n';
	}
}