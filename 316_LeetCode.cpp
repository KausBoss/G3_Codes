#include <bits/stdc++.h>

using namespace std;
#define ll long long

string removeDuplicateLetters(string S) {
    int LS[26];
    for(int i=0; i<S.length(); i++){
    	LS[S[i]-'a']=i;
    }
    bool pres[26]={0};memset(pres, false, sizeof(pres));
    deque<char> d;
    for(int i=0; i<S.length(); i++){
    	if(d.empty()){
    		d.push_back(S[i]);
            pres[S[i]-'a']=true;
    	}
    	else{
    		while(!d.empty()&& pres[S[i]-'a'] == 0&&S[i] < d.back() && LS[d.back()-'a'] > i){
    			pres[d.back()-'a']=false;
    			d.pop_back();
    		}
    		if(!pres[S[i]-'a']){d.push_back(S[i]);pres[S[i]-'a']=true;}
    	}
    }
    string ret;
    while(!d.empty()){
    	ret += d.front();
    	d.pop_front();
    }
    return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s= "abacb";
	cout<<removeDuplicateLetters(s);
	
}

