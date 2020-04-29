#include <bits/stdc++.h>

using namespace std;
#define ll long long

string removeOuterParentheses(string S) {
    string ans="", temp="";
    stack<char> s;
    for(auto x:S){
    	if(x=='('){s.push(x);}
    	if(x==')'){s.pop();}
    	temp += x;
    	if(s.empty()){
    		//cout<<temp<<endl;
    		ans.append(temp.begin()+1, temp.end()-1);
    		temp ="";
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
	string s= "(()())(())";
	cout<<removeOuterParentheses(s);
}