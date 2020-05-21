#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n=-26;
	n = -n;
	n = ~n;
	n +=1;
	string s="";
	while(__builtin_popcount(n) > 0){
	//while(n > 0){
        int mask = (1<<4) - 1;
        int v = n&mask;
        n = n>>4;
        if(v > 9){
            v -= 10;
            s.push_back( 'a' + v);
        }
        else{
            s.push_back( '0' + v);
        }
        cout<<s<<endl;
    }
    reverse(s.begin() , s.end());
    cout<<s;
}