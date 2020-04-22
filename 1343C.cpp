#include <bits/stdc++.h>

using namespace std;
#define ll signed long long
#define inf 200005

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t, n, a[inf];
	cin>>t;
	while(t--){
		cin>>n;	
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}

		ll sum=0, max_num, i=0, j=0;
		for(ll i=0; i<n;){
			max_num= a[i];
			j=i;
			while(j<n && signbit(a[i])==signbit(a[j])){
				max_num= max(max_num, a[j]);
				j++;
			}
			sum += max_num;
			i=j;
		}
		cout<<sum<<endl;
	}
}