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
		int n, s, a[101] , p;
		int mindef=200, midfor=200;
		cin>>n>>s;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			cin>>p;
			if(p==0){
				mindef=min(mindef, a[i]);
			}
			else{
				midfor=min(midfor, a[i]);
			}		
		}
		if((midfor+mindef+s) <=100){
			cout<<"yes\n";
		}
		else{cout<<"no\n";}
	} 	
}