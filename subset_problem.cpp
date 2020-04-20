#include <bits/stdc++.h>

using namespace std;
#define ll long long
int total=0;

void print(vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<" ";
}

void subset(int a[], int n, int i, int sum, vector<int> ans, int target){
	//base case
	if(i==n){
		if(sum == target){
			print(ans);
			total++;
		}
		return;
	}
	//recursive case
	sum += a[i];
	ans.push_back(a[i]);
	subset(a, n, i+1, sum, ans, target);
	sum -=a[i];
	ans.pop_back();
	subset(a, n, i+1, sum, ans, target);
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> ans;
	int n, a[100], target;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>target;
	subset(a, n, 0, 0, ans, target);
	cout<<endl<<total;
}