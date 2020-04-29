#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isValid(string S) {
    stack <char> s;
    for(int i=1; i<S.length()-1; i++){
    	if(s.empty()&&S[i]=='a'){
    		s.push('a');
    	}
    	else if(s.size()==1){
    		if(S[i]=='b'){
    			s.push('b');
    		}
    		else{
    			s= stack<char> ();
    			if(S[i]=='a'){s.push('a');}
    		}
    	}
    	else if(s.size()==2){
    		if(S[i]=='c'){
    			return true;
    		}
    		else{
    			s= stack<char> ();
    		}
    	}
    	cout<<s.top()<<" ";
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s="aabcbc";
	cout<<isValid(s);
	
}