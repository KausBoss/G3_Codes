#include <bits/stdc++.h>

using namespace std;
#define ll long long


int MaxProf[100]={0};

int MaxProfit(int cost[], int totallen){
	//basse case
	if(totallen == 0){
		return 0;
	}
	//recusrive case
	if(MaxProf[totallen]!=0){return MaxProf[totallen];}
	
	int ret=INT_MIN;
	for(int i=1; i<=totallen; i++){
		ret = max(ret, cost[i] + MaxProfit(cost, totallen-i));
	}

	MaxProf[totallen]=ret;
	return ret;
}

int Profit_BottomUp(int cost[], int totallen){

	for(int i=1; i<=totallen; i++){
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int costperlen[10];
	int totallen;
	cin>>totallen;
	for(int i=1; i<=totallen; i++){
		cin>>costperlen[i];
	}
	cout<<MaxProfit(costperlen, totallen);
}