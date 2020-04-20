#include <iostream>
#include <string>

using namespace std;

void MakeTable(string p, int table[]){
	int n=p.length();
	int i=0, j=1;
	while(j<n){
		if(p[i]!=p[j]){
			if(i==0){
				j++;
			}
			else{
				i=0;
			}
		}
		else{
			table[j]=i+1;
			i++;
			j++;
		}
	}
	for(int i=0; i<n; i++){
		cout<<table[i]<<" ";
	}
}

void KMP(string s, string p, int table[]){
	int i=0; int j=0;
	int ls=s.length();
	int lp=p.length();

	while(i<ls){
		while(j>0&& s[i]!=p[j]){
			j = table[j-1];
		}

		if(s[i]==p[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
		if(j==lp){
			cout<<"Pattern Found at index "<<i-j<<"\n";
			j= table[j-1];
		}
	}
}


int main(){
	string p="ABCDABC";
	string s="ABCDABCDABCDABCDABCXABCDABC";
	int table[p.length()]={0};
	MakeTable(p, table);
	KMP(s, p, table);
}