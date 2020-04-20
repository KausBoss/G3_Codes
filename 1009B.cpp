#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>>s;
	int n=s.length();
	int ones=0;
	for(int i=0;i<n; i++){
		if(s[i]=='1'){ones++;}
	}
	bool flag=true;
	for(int i=0; i<n; i++){
		if(s[i]!='1'){
			if(s[i]=='2'&&flag){
				while(ones--){cout<<1;}
				flag=false;
			}
			cout<<s[i];
		}
	}
	if(flag){
		while(ones--){cout<<1;}
	}
	//cout<<s;
}