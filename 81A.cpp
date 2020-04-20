#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int n = s.length();
	deque<char> dd;
	for(int i=0; i<n; i++){
		if(dd.empty()){
			dd.push_back(s[i]);
		}
		else if(s[i] == dd.back()){
			dd.pop_back();
		}
		else{
			dd.push_back(s[i]);
		}
	}
	while(!dd.empty()){
		cout<<dd.front();
		dd.pop_front();
	}
}