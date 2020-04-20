#include <bits/stdc++.h>

using namespace std;

class wow{
public:
	int digi;
	int freq;
	int seen;
	wow(){
		freq=0;
		seen=-1;
	}
	void print(){
		cout<<digi<<" "<<freq<<" "<<seen<<"\n";
	}
};

struct comp{
	bool operator()(wow a, wow b){
		if(a.freq == b.freq){
			return a.seen > b.seen;
		}
		return a.freq < b.freq;
	}
};

wow a[100005]; 

int main(){
	int n, m, num;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>num;
		a[num].digi= num;
		a[num].freq++;
		if(a[num].seen==-1){
			a[num].seen=i;
		}
	}

	priority_queue<wow, vector<wow>, comp> p;
	for(int i=1; i<=m; i++){
		if(a[i].freq > 0){
			p.push(a[i]);
		}
	}

	while(!p.empty()){
		wow temp=p.top();
		//temp.print();
		p.pop();
		for(int i=0; i<temp.freq; i++){
			cout<<temp.digi<<" ";
		}
	}
}