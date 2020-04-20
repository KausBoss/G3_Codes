#include <bits/stdc++.h>

using namespace std;
#define ll long long
int ct=0;

void twin(char ch[], int i){
	//base case
	if(ch[i]=='\0'){
		return;
	}
	//recursive case
	if(ch[i-2] == ch[i]){ct++;}
	twin(ch, i+1);	
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[100];
	cin>>ch;
	twin(ch, 2);
	cout<<ct;
}