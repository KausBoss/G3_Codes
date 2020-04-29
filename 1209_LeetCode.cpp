#include <bits/stdc++.h>

using namespace std;
#define ll long long

string removeDuplicates(string st, int k) {
    char c;
    bool beet;
    deque<char> s;
    for(auto x:st){
    	beet=false;
    	if(s.empty()){
    		s.push_back(x);
    	}
    	else{
    		if(x!=s.back()){
    			c=s.back();
    			s.pop_back();
    			while(!s.empty() && s.back()==c && k>0){
    				beet = true;
    				s.pop_back();
    			}
    			if(beet){k--;}
    			else{s.push_back(c);}
    		}
    		s.push_back(x);
    	}
    	cout<<s.front()<<"  "<<s.size()<<"  "<<s.back()<<endl;
    }
    string ans="";
    while(!s.empty()){
    	ans += s.front();
    	s.pop_front();
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
	string s="deeedbbcccbdaa";
	cout<<s<<endl;
	cout<<removeDuplicates(s, 3);
}