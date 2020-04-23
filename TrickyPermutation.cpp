#include <bits/stdc++.h>

using namespace std;
#define ll long long

set<string> ans;

void permute(string s, int i){
	//base case
	if(i == s.length()){
		ans.insert(s);
		return;
	}
	//recursive case
	bitset<26> freq;
	freq[s[i] - 'a']=1;
	for(int j=i; j<s.length(); j++){
		if(j==i || freq[s[j]-'a']==0){
			freq[s[j] - 'a']=1;
			swap(s[j], s[i]);
			permute(s, i+1);
			swap(s[j], s[i]);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s1;
	sort(s1.begin(), s1.end());
	cin>>s1;
	permute(s1, 0);
	for(auto x:ans){
		cout<<x<<endl;
	}
}