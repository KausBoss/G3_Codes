#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void func(){
	ll u, v, x;
	cin>>u>>v;
	if(u > v || (v-u)%2 == 1){
		cout<<-1;
		return;
	}
	if(u == v && u == 0){
		cout<<0;
		return;
	}
	if(u == v){
		cout<<1<<endl<<u;
		return;
	}
	x = (v-u)/2;
	if((x&u)==0){
		cout<<2<<endl<<x<<" "<<x+u;
		return;
	}
	else{
		cout<<3<<endl<<x<<" "<<x<<" "<<u;
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	func();
}