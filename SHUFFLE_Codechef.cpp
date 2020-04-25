#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll k, n, temp;
		cin>>n>>k;
		ll flag=3;
		vector<vector <ll> > v(k);
		int ar[100001];
		for(int i=0; i<n; i++){
			cin>>temp;
			ar[i]=temp;
			int id=(i%k);
			v[id].push_back(temp);
		}
		if(k==1){cout<<"yes\n"; continue;}
		for(int i=0; i<k; i++){
			sort(v[i].begin(), v[i].end());
		}
		// for(int i=0; i<k; i++){
		// 	for(int j=0; j<v[i].size(); j++){
		// 		cout<<v[i][j]<<"==";
		// 	}
		// 	cout<<endl;
		// }
		sort(ar, ar+n);
		ll lim= ceil((float)n/(float)k);

		for(int i=0; i<lim; i++){
			if((i==lim-1)&&(n%k)!=0){
				for(int j=0; j<(n%k); j++){
					ll pos=(i*k) + j;
					//cout<<ar[pos]<<"--"<<v[j][i]<<endl;
					if(ar[pos] != v[j][i]){
						cout<<"no\n";
						flag=12;
						break;
					} 
				}
			}
			else{
				for(int j=0; j<k; j++){
					ll pos=(i*k) + j;
					//cout<<ar[pos]<<"--"<<v[j][i]<<"--"<<pos<<"  index "<<i<<", "<<j<<endl;
					if(ar[pos] != v[j][i]){
						cout<<"no\n";
						flag=12;
						break;
					} 
				}
			}
			if(flag=12){break;}
		}
		if(flag!=12){cout<<"yes\n";}
		v.clear();
	}
}