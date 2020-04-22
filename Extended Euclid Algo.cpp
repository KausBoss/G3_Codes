#include <bits/stdc++.h>

using namespace std;
#define ll long long


int x, y;
void ExtendedEA(int a, int b){
	//base case
	if(b==0){
		x=1;
		y=0;
		return;
	}
	//recursive case
	ExtendedEA(b, a%b);
	int cx=y;
	int cy=x - (a/b)*y;
	x=cx;
	y=cy;
	cout<<x<<" "<<y<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int a, b;
	cin>>a>>b;
	ExtendedEA(a, b);
}