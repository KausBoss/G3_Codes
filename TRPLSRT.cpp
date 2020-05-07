#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define inf (int)1e5

void func(){
	int n, a[inf], diff=0;
	map<int, int> m;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]!=i+1){
			diff++;
			m[a[i]]=i;
		}
	}
	if(dif%3!=0){cout<<-1<<"\n"; return;}
	for()


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
	while(t--){
		func();
	}
}