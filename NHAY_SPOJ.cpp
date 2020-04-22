#include <bits/stdc++.h>

using namespace std;
#define ll long long


void KMP(string needle, string hay, int n){
	//first making the pi table
	int table[n]={0};
	int i=0, j=1;
	bool flag=false;
	while(j<n){
		if(needle[i] == needle[j]){
			table[j]=i+1;
			i++;
		}
		else if(needle[i]!=needle[j] && i>0){
			i=0;
		}
		j++;
	}
	i=0;
	j=0;
	while(i<hay.length()){
		if(hay[i]!=needle[j] && j>0){
			j=table[j-1];
		}
		if(hay[i] == needle[j]){
			i++;j++;
		}
		else {
			i++;
		}
		if(j==n){
			flag = true;
			cout<<i-j<<endl;
			j=table[j-1];
		}
	}
	if(!flag){cout<<endl;}
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	string needle, hay;
	while(cin>>n>>needle>>hay){
		KMP(needle, hay, n);
	}
}