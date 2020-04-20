#include <bits/stdc++.h>

using namespace std;
#define ll long long

set<string> s;

void permute(char *ch, int i){
	//base case
	if(ch[i]=='\0'){
		//string st= to_string(ch);
		//s.insert(ch);
		cout<<ch<<" ";
		return;
	}
	//recurisve case
	for(int j=i; ch[j]!='\0'; j++){
		swap(ch[i], ch[j]);
		permute(ch, i+1);
		swap(ch[i], ch[j]);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[100];
	cin>>ch;
	permute(ch, 0);
	// for(auto x:s){
	// 	cout<<x<<" ";
	// }
}