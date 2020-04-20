#include <bits/stdc++.h>

using namespace std;
#define ll long long

int Count=0;

void path(int n1, int n2, int i, int j, int k, char ch[]){
	//base case
	if(i==(n1-1) && j==(n2-1)){
		ch[k]='\0';
		cout<<ch<<" ";
		Count++;
		return;
	}
	if(i>=n1){return;}
	if(j>=n2){return;}
	//recursive case
	ch[k]='V';
	path(n1, n2, i+1, j, k+1, ch);
	ch[k]='H';
	path(n1, n2, i, j+1, k+1, ch);
	ch[k]='D';
	path(n1, n2, i+1, j+1, k+1, ch);
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n1, n2;
	char ch[100];
	cin>>n1>>n2;
	path(n1, n2, 0, 0, 0, ch);
	cout<<"\n"<<Count;
}