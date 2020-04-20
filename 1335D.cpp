#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a[9][9];
		for(int i=0; i<9; i++){
			string s;
			cin>>s;
			for(int j=0; j<9; j++){
				a[i][j]= s[j]- '0';
			}

		}

		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(a[i][j]==1){cout<<2;}
				else{cout<<a[i][j];}
			}
			cout<<"\n";
		}
	}
}