#include <bits/stdc++.h>

using namespace std;
#define ll long long

void func(){
	string s;
	cin>>s;
	int n=s.length();
	if(s.length()<=2){
		cout<<"YES\n";
		return;
	}
	if(s.length()%2==1 && s[0]!=s[1]){cout<<"NO\n"; return;}

	for(int i=2; i<n; i+=2){
		if(s[i]!=s[0]){
			cout<<"NO\n"; return;
		}
	}
	for(int i=3; i<n; i+=2){
		if(s[i]!=s[1]){
			cout<<"NO\n"; return;	
		}
	}
	cout<<"YES\n";
	return;
}


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
		func();
	}
}