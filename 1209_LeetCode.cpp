#include <bits/stdc++.h>

using namespace std;
#define ll long long

string removeDuplicates(string S, int k) {
    int temp=1;
    deque<pair<char, int>> d;
    for(char x:S){
    	if(!d.empty()){
    		cout<<d.front().first<<" "<<d.front().second<<" "<<d.back().first<<" "<<d.back().second<<endl;
    	}
    	if(d.empty()){
    		d.push_back(make_pair(x, temp));
    	}
    	else{
    		if(x==d.back().first){temp=d.back().second+1;}
    		else{temp=1;}
    		d.push_back(make_pair(x, temp));
    		if(d.back().second==k){
    			while(temp--){d.pop_back();}
    			temp=1;
    		}
    	}
    }
    string ans="";
    while(!d.empty()){
    	ans +=d.front().first;
    	d.pop_front();
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
	string s="pbbcggttciiippooaais";
	cout<<removeDuplicates(s, 2);
}