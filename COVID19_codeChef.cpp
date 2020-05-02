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
		int n, a[8];
		int less=INT_MAX, more=INT_MIN;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int curr=1;
		for(int i=1; i<n; i++){
			if(a[i]-a[i-1] <=2){
				curr++;
			}
			else{
				less = min(less, curr);
				more = max(more, curr);
				curr=1;
			}
		}
		less = min(less, curr);
		more = max(more, curr);
		cout<<less<<" "<<more<<"\n";
	}
}