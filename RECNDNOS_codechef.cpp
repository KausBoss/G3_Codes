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
	int t;
	cin>>t;
	while(t--){
		int n, a[1000], val[1002]={0};
		cin>>n;
		int i;
		for(i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			if(i==n-1){val[a[i]]++; break;}
			if(a[i] == a[i+1]){
				val[a[i++]]++;
			}
			else{val[a[i]]++;}
		}
		int ct=INT_MIN;
		int ans;
		for(int i=0; i<1002; i++){
			if(val[i] > ct){
				ans=i;
				ct=val[i];
			}
		}
		cout<<ans<<endl;
	}
}