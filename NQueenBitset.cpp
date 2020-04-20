#include <bits/stdc++.h>

using namespace std;
#define ll long long

bitset<50> rd, ld, col;
int ans=0;

void NQueen(int n, int i, vector <int> id){
	//base case
	if(i == n){
		ans++;
		for(int i=0; i<n; i++){
			cout<<"{"<<i+1<<"-"<<id[i]<<"} ";
		}
		cout<<" ";
		return;
	}
	//recursive case
	for(int j=0; j<n; j++){
		if((!col[j]) && (!rd[i+j]) && (!ld[i-j+n-1])){
			col[j]=rd[i+j]=ld[i-j+n-1]=1;
			id.push_back(j+1);
			NQueen(n, i+1, id);
			col[j]=rd[i+j]=ld[i-j+n-1]=0;
			id.pop_back();
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	vector<int> v;
	cin>>n;
	NQueen(n, 0, v);
	cout<<endl<<ans;
}