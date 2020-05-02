#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool find132pattern(vector<int> S) {
    stack<int> s;
    int s3_max=INT_MIN;
    for(int i=S.size()-1; i>=0; i--){
    	if(S[i]<s3_max){return true;}
    	if(s.empty()){
    		s.push(S[i]);
    	}
    	else{
    		while(!s.empty() && s.top()<S[i]){
    			s3_max = max(s3_max, s.top());
    			s.pop();
    		}
    		s.push(S[i]);
    	}
    	//cout<<S[i]<<" "<<s3_max<<" "<<s.size()<<endl;
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
	vector<int> v{9, 11, 8, 9, 10, 7, 9};
	cout<<find132pattern(v);
}
