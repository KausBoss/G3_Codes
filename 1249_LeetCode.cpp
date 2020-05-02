#include <bits/stdc++.h>

using namespace std;
#define ll long long

string minRemoveToMakeValid(string s) {
    string ans="";
    deque<pair<char,int>> d;
    for(int i=0; i<s.size(); i++){
    	if(s[i]=='('||s[i]==')'){
    		if(d.empty()){
    			d.push_back(make_pair(s[i], i));
    		}
    		else{
    			if(s[i]==')'&&d.back().first=='('){
    				d.pop_back();
    			}
    			else{
    				d.push_back(make_pair(s[i], i));
    			}
    		}
    	}
    }
    for(int i=0; i<s.size(); i++){
    	if(d.empty()){
    		ans += s[i];
    	}
    	else{
    		if(i==d.front().second){
    			d.pop_front();
    		}
    		else{
    			ans += s[i];
    		}
    	}
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s="lee(t(c)o)de)";
	cout<<minRemoveToMakeValid(s);
}
