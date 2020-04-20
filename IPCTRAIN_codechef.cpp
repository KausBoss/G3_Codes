#include <bits/stdc++.h>

using namespace std;
#define inf 100005

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		priority_queue<pair<int, int> > pq;
		int ans=0, id, n, d, ar[inf], lec[inf], sad[inf];
		bitset<inf> dleft;
		cin>>n>>d;
		for(int i=0; i<n; i++){
			cin>>ar[i]>>lec[i]>>sad[i];
			//ar[i]--;
			pq.push(make_pair(sad[i], i));
		}

		while(!pq.empty()){
			id=pq.top().second;
			pq.pop();
			for(int i=ar[id]; i<=d; i++){
				if(lec[id]==0){ break;}

				if(dleft[i]==0){
					lec[id]--;
					dleft[i]=1;
				}
			}
		}

		for(int i=0; i<n; i++){
			ans += sad[i]*lec[i];
		}
		cout<<ans<<"\n";
	}
}