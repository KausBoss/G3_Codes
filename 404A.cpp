#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char ch[299][299], d, o;
	cin>>n; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>ch[i][j];
		}
	}
	d = ch[0][0];
	o = ch[0][1];
	if(d == o){
		cout<<"NO";
		return 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j || i+j==n-1){
				if(ch[i][j]!=d){
					cout<<"NO";
					return 0;
				}
			}
			else{
				if(ch[i][j]!=o){
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
}