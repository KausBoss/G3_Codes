#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif 	
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	for(int i=n-2; i>=0; i--){
		int start =1;
		int end=s[i].length();
		string ans;
		while(start <= end){
			int mid = (start + end)/2;
			string str = s[i].substr(0, mid);
			if(str <= s[i+1]){
				ans = str;
				start = mid+1;
			}
			else{
				end=mid-1;
			}
		} 
		s[i] = ans;
	}
	for(auto x:s){
		cout<<x<<endl;
	}
}