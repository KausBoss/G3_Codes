#include <bits/stdc++.h>

using namespace std;
vector<string> sst;

void print(char *ch, char *op, int i, int j){
	//base case
	if(ch[i]=='\0'){
		op[j]='\0';
		sst.push_back(op);
		//cout<<op<<", ";
		return;
	}
	//recusrive case
	int at_i=ch[i]-'0';	int next= at_i*10+(ch[i+1]-'0');
	//cout<<i<<"--"<<at_i<<"--"<<next<<endl;1125
	op[j]=at_i+'a'-1;
	print(ch, op, i+1, j+1);
	if(next<=26&&ch[i+1]!='\0'){
		op[j]='a'+next-1;
		print(ch, op, i+2, j+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[1000], op[1000];
	cin>>ch;
	print(ch, op, 0, 0);
	cout<<"[";
	for(int i=0; i<sst.size(); i++){
		if(i==sst.size()-1){
			cout<<sst[i];
		}
		else{
			cout<<sst[i]<<", ";
		}
	}
	cout<<"]";
}