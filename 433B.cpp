#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define ll long long
#define inf 100005

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, a[inf], sum[inf]={0}, sorted_sum[inf]={0};
	ll m, type, l, r;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		sum[i] = sum[i-1]+a[i];
	}
	sort(a+1, a+1+n);

	for(int i=1; i<=n; i++){
		sorted_sum[i] = sorted_sum[i-1]+a[i];
	}
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>type>>l>>r;
		if(type==1){
			cout<<sum[r]-sum[l-1]<<"\n";
		}
		else{
			cout<<sorted_sum[r]-sorted_sum[l-1]<<"\n";
		}
	}
}