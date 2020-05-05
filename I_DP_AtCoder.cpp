#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n;
double a[3000];
double dp[3000][3000];

double func(int i, int kitne){
	//base case
	if(kitne == 0){return 1;}
	if(i == n){return 0;}
	//recursive case
	if(dp[i][kitne]>-1.0){return dp[i][kitne];}

	double case1= a[i]*func(i+1, kitne-1);
	double case2= (1-a[i])*func(i+1, kitne);

	dp[i][kitne]= case1+case2;

	return dp[i][kitne];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	memset(dp, -1.0, sizeof(dp));
	double ans=0;
	cout<<setprecision(10)<<func(0, (n+1)/2);
}