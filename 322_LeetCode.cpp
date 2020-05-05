#include <bits/stdc++.h>

using namespace std;
#define ll long long
map<int, pair<int,bool>> m;

int coinChange(vector<int> c, int a){
    int dp[a+1];
    dp[0]=0;

    for(int i=1; i<=a; i++){
        dp[i]=50000;
        for(auto x:c){
            if(x<=i){
                dp[i]=min(dp[i], 1+dp[i-x]);
            }
        }
    }
    return dp[a]>=50000?-1:dp[a];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{463,351,30,129,434,91,120,205,205};
	cout<<coinChange(v,4863);
}

