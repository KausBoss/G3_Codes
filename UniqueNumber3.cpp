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
	int n, x, bit[32]={0}, ans=0;
	cin>>n;
	while(n--){
		cin>>x;
		int pos=0;
		while(x > 0){
			if(x&1){
				bit[pos]++;
				bit[pos] %= 3;
			}
			pos++;
			x = x>>1;
		}
	}
	for(int i =0; i<32; i++){
		if(bit[i]){
			ans |= (1<<i);
		}
	}
	cout<<ans;
}