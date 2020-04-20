#include <bits/stdc++.h>

using namespace std;
#define ll long long
int ct=0;

void subsequence(char *ip, string op, int i){
	//base case
	if(ip[i]=='\0'){
		op+= "\0";
		cout<<op<<" ";
		ct++;
		return;
	}
	//recursive case
	subsequence(ip, op, i+1);
	op += ip[i];
	subsequence(ip, op, i+1);
	op.erase(op.length()-1, op.length());
	op += to_string((int)ip[i]);
	subsequence(ip, op, i+1);
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[100];
	string s;
	cin>>ch;
	subsequence(ch, s, 0);
	cout<<endl<<ct;
}