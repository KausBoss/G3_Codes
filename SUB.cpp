#include <bits/stdc++.h>

using namespace std;
#define ll long long

int ct=0;
void subsequences(char *ip, char *op, int i, int j){
	//base case
	if(ip[i]=='\0'){
		op[j]='\0';
		cout<<op<<" ";
		ct++;
		return;
	}
	//recursive case
	subsequences(ip, op, i+1, j);
	op[j]=ip[i];
	subsequences(ip, op, i+1, j+1);
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ip[100], op[100];
	cin>>ip;
	subsequences(ip, op, 0, 0);
	cout<<endl<<ct;
}