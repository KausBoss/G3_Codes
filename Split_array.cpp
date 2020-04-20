#include <bits/stdc++.h>

using namespace std;
#define ll long long
int total=0;

void split(int a[], int i, int n, int s1, int s2, vector<int> sum1,vector  <int> sum2){
	//base case
	if(i==n){
		if(s1 == s2){
			for(int i=0; i<sum1.size();i++){cout<<sum1[i]<<" ";}
			cout<<"and ";
			for(int i=0; i<sum2.size();i++){cout<<sum2[i]<<" ";}
			cout<<endl;
			total++;
		}
		return;
	}
	//recursive case
	sum1.push_back(a[i]);
	split(a, i+1, n, s1+a[i], s2, sum1, sum2);
	sum1.pop_back();
	sum2.push_back(a[i]);
	split(a, i+1, n, s1, s2+a[i], sum1, sum2);
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v1, v2;
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	split(a, 0, n, 0, 0,  v1, v2);
	cout<<total;
}