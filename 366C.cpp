#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,k;
int taste[100], cal[100];
map<pair<int,int>, int> m;

int func(int i, int sum){
	//base case
	if (i==n){
		if(sum==0){return 0;}
		else{return INT_MIN;}
	}
	//recursive case
	if(m.count(make_pair(i, sum))){return m[make_pair(i, sum)];}
	int op1 = taste[i] + func(i+1,sum + taste[i]- k*cal[i]);
	int op2 = func(i+1, sum);
	m[make_pair(i, sum)] = max(op1, op2);
	return max(op1,op2);
}
	
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>taste[i];
	}
	for (int i=0; i<n; i++){
		cin>>cal[i];
	}
	int f= func(0,0)?func(0,0):-1;
	cout<<f;	
}