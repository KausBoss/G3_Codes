#include <bits/stdc++.h>

using namespace std;
#define ll long long
void MakeTable(string p, ll table[]){
	ll n=p.length();
	ll i=0, j=1;
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
}

bool KMP(string s, string p, ll table[]){
	ll i=0; ll j=0;
	ll ls=s.length();
	ll lp=p.length();

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
			return true;
			j= table[j-1];
		}
	}
	return false;
}

int main(){
	ll t, n, last, cur;
	cin>>t;
	while(t--){
		cin>>n;
		string s, p;
		ll table[100001]={0};
		cin>>last;
		for(ll i=1;i<n; i++){
			cin>>cur;
			if(cur==last){s.append("E");}
			if(cur>last){s.append("G");}
			else{s.append("L");}
			last=cur;
		}
		cin>>p;
		MakeTable(p, table);
		if(KMP(s, p, table)){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
}