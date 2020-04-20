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
	// for(int i=0; i<n; i++){
	// 	cout<<table[i]<<" ";
	// }
}

bool KMP(string s, string p, int table[]){
	bool what=true;
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
			bool what=false;
			cout<<i-j<<"\n";
			j= table[j-1];
		}
	}
	return what;
}


int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// string p, s;
	// // int t;
	// // cin>>t;
	// // while(t--){
	// int len;
	// cin>>len>>p>>s;
	// MakeTable(p, table);
	// if(KMP(s, p, table)){
	// 	cout<<"\n";
	// }
	int m;
    bool first = true;
    while (scanf("%d",&m)==1) {
	    if (!first) puts("");
	    first = false;
	    int table[m]={0};
	    string needle; //getline(cin, needle);
	    getline(cin, needle);
	    MakeTable(needle, table);
	    string haystack;
	    getline(cin, haystack);
	    KMP(haystack, needle, table);
  	}
  return 0;
}