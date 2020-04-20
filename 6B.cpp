#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	char ch[100][100], prez;
	set<char> s;
	cin>>n>>m>>prez;
	for(int i=0;i<n; i++){
		for(int j=0; j<m; j++){
			cin>>ch[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(ch[i][j]==prez){
				if(i!=0){
					if(ch[i-1][j]!='.' && ch[i-1][j]!=prez){
						s.insert(ch[i-1][j]);
					}
				}
				if(j!=0){
					if(ch[i][j-1]!='.' && ch[i][j-1]!=prez){
						s.insert(ch[i][j-1]);
					}
				}
				if(i!=n-1){
					if(ch[i+1][j]!='.' && ch[i+1][j]!=prez){
						s.insert(ch[i+1][j]);
					}
				}
				if(j!=m-1){
					if(ch[i][j+1]!='.' && ch[i][j+1]!=prez){
						s.insert(ch[i][j+1]);
					}
				}
			}
		}
	}
	cout<<s.size();
}