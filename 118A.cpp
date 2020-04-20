#include <bits/stdc++.h>

using namespace std;

int main(){
	char ch[100];
	cin>>ch;
	for(int i=0; ch[i]!='\0'; i++){
		if(ch[i]=='Y'||ch[i]=='y'||ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U'||ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u'){
			continue;
		}
		else{
			cout<<"."<<(char)tolower(ch[i]);
		}
	}	
}