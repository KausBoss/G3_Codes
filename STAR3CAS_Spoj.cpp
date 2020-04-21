#include <bits/stdc++.h>

using namespace std;
#define ll long long

int MinStep(int *a, int i, int n, bitset<20> vst, int steps){
	//base case 
	if(i==n){
		return 0;
	}
	//recusive case
	
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n, a[20];
		bitset<20> vst;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		cout<<MinStep(a, i, n, vst);
	}
}