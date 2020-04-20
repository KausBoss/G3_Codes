#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ll n, scoreA=0, scoreB=0, temp;
	vector<int> a, b;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		if(temp>0){
			a.push_back(temp);
			scoreA += temp;
		}
		else{
			b.push_back(-temp);
			scoreB += -temp;
		}
	}

	if(scoreA!=scoreB){
		scoreA > scoreB ? cout<<"first": cout<<"second";
		return 0;
	}

	if(a!=b){
		for(int i=0; i<a.size(), i<b.size(); i++){
			if(a[i] > b[i]){ cout<<"first"; return 0;}
			if(a[i] < b[i]){ cout<<"second"; return 0;}
		}
		a.size() > b.size() ? cout<<"first":cout<<"second";
		return 0;
	}	

	temp > 0 ? cout<<"first": cout<<"second";
	return 0;
}