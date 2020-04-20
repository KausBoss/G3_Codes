#include <bits/stdc++.h>

using namespace std;

void LowerKardo(string &s){
	for(int i=0; i<s.length(); i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i] +=32;
		}
	}
}

int main(){
	string a,b;
	cin>>a>>b;
	LowerKardo(a);
	LowerKardo(b);
	if(a==b){
		cout<<0;
	}
	else if(a>b){
		cout<<1;
	}
	else {
		cout<<-1;
	}
}