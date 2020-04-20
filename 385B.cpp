#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define ll long long 

int count(vector<int> v, int n){
	int ret=0;
	for(int i=0; i<v.size(); i++){
		ret += i==0 ? (v[i]+1)*(n-(v[i]+3)) : (v[i]-v[i-1])*(n-(v[i]+3)) ;
	}
	return ret;
}

int main(){
	vector<int> index;
	string s, k="bear";
	int ans=0;
	cin>>s;
	int n=s.length();
	size_t f=s.find(k);
	//cout<<f<<"--";
	while(f!=string::npos){
		//int id = f-s.begin();
		//cout<<f<<"--"<<"\n";
		index.push_back((int)f);
		f = s.find(k, f+4);
	}
	ans = count(index, n);

	cout<<ans;
}