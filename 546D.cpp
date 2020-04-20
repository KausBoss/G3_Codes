#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
#define inf 5000010
#define ll long long

bitset<inf> pr;

vector<ll> diviser(inf+1, 1); 
vector<ll> Factor(inf+1, 0);
vector<ll> SumOfFact(inf+1, 0);


void sieve(){
	pr[0]=pr[1]=1;
	for(ll i=2; i*i<=inf; i++){
		if(!pr[i]){
			for(ll j=2*i; j<=inf; j+=i){
				pr[j]=1;
				diviser[j]=i;
			}
		}
	}
}

void counting(){
	for(ll i=2; i<=inf; i++){
		if(!pr[i]){
			Factor[i]=1;
		}
		else{
			Factor[i] = Factor[i/diviser[i]] +1;
		}
		SumOfFact[i] = SumOfFact[i-1] + Factor[i];
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	sieve();
	counting();
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		cout<<SumOfFact[a]-SumOfFact[b]<<"\n";
	}
}