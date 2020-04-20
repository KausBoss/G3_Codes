#include <bits/stdc++.h>

using namespace std;

class dancer{
public:
	int no;
	int pos;
	int time;
	int dir;
	dancer(int num, int pos, int time, int dir){
		no=num;
		this->pos=pos;
		this->time=time;
		this->dir=dir;
	}
};

bool compi(dancer a, dancer b){
	return a.pos < b.pos;
}

bool finalsort(dancer a, dancer b){
	return a.no < b.no;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int w, h, n, a, b, type;
	vector<dancer> xwale, ywale;
	cin>>n>>w>>h;
	for(int i=0; i<n; i++){
		cin>>type>>a>>b;
		dancer d(i+1, a, b, type);
		if(type==1){
			xwale.push_back(d);
		}
		else{
			ywale.push_back(d);
		}
	}

	sort(xwale.begin(), xwale.end(), compi);
	sort(ywale.begin(), ywale.end(), compi);

	for(int i=0; i<xwale.size(); i++){
		for(int j=0; j<ywale.size(); j++){
			if(xwale[i].time + ywale[j].pos == ywale[j].time + xwale[i].pos){
				swap(xwale[i].no, ywale[j].no);
			}
		}
	}
	xwale.insert(xwale.end(), ywale.begin(), ywale.end());

	sort(xwale.begin(), xwale.end(), finalsort);

	for(int i=0; i<xwale.size(); i++){
		if(xwale[i].dir == 1){
			cout<<xwale[i].pos<<" "<<h<<"\n";
		}
		else{
			cout<<w<<" "<<xwale[i].pos<<"\n";
		}
	}

}