#include <bits/stdc++.h>

using namespace std;

#define ll long long

int gcd(int a, int b){
	return b==0?a:gcd(b, a%b);
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
	for(int ii=1; ii<=t; ii++){
		cout<<"Case "<<ii<<": ";
		int a, b, c;
		cin>>a>>b>>c;
		if(a<b){swap(a, b);}
		if(c%gcd(a, b)==0){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}