#include <bits/stdc++.h>

using namespace std;
#define ll long long
int a[1000];
int dp[1000][1000];

int wine(int i, int j, int day){
	//base case
	if(i>j){return 0;}

	//recursive case
	if(dp[i][j]!=-1){return dp[i][j];}

	dp[i][j]= max(day*a[i] + wine(i+1,j, day+1), day*a[j] + wine(i,j-1, day+1));

	return dp[i][j];
}
int bottomup(){
	int dp[100][100]={0};

	for(int i=n; i>=0; i--){
		for(int j=0; j<=n; j++){
			if(i>j){
				dp[i][j]=0;
			}
			else{
				int cd= n-(j-i);
				int op1=a[i]*cd + dp[i+1][j];
				int op2=a[j]+cd + dp[i][j-1];
				dp[i][j]= min(op1, op2);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<wine(0, n-1, 1);
}