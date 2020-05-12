#include <bits/stdc++.h>

using namespace std;
#define ll long long
double dp[101][101][101];

double winner(int r, int s, int p){
	//base case
	if(r==0 || s==0){return 0.0;}
	if(p == 0){return 1.0;}
	//recursive case
	if(dp[r][s][p]>-1.0){return dp[r][s][p];}
	double ans=0;
	double total = r*s + s*p + p*r;

	ans += ((r*s)/total) * winner(r, s-1, p);
	ans += ((r*p)/total) * winner(r-1, s, p);
	ans += ((s*p)/total) * winner(r, s, p-1);

	return dp[r][s][p]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	int r, p, s;
	while(t--){
		memset(dp, -1, sizeof(dp));
		cin>>r>>s>>p;
		cout<<fixed<<setprecision(9)<<winner(r,s,p)<<" "<<winner(s,p,r)<<" "<<winner(p,r,s)<<endl;
	}
	

}