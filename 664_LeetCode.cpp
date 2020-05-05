#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<pair<int,string>, int> m;

int cross(string x, int i, string s){
	//base case
	if(i == s.length()){
		return 0;
	}
	//recursive case
	if(x.length()-1 >= i && x[i]==s[i]){return cross(x, i+1, s);}
	if()
}

int strangePrinter(string s) {
	string ans=s;
	return func("", 0, s);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<strangePrinter("aaaaaa");
}
