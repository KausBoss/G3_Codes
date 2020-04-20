#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool funky(char *ch, int i){
	//base case
	if(ch[i]=='\0'){
		return true;
	}
	if(i==0&&ch[i]!='a'){return false;}
	if(ch[i]=='a'){
		if((ch[i+1]=='a') || (ch[i+1]=='\0')){
			return funky(ch, i+1);
		}
		else if(((ch[i+1]=='b')&&(ch[i+2]=='b'))){
			return funky(ch, i+2);
		}
		else{return false;}
	}

	if(ch[i]=='b'){
		if(ch[i+1]=='a' || ch[i+1]=='\0'){
			return funky(ch, i+1);
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[100];
	cin>>ch;
	if(funky(ch, 0)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	
}