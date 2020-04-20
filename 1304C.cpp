#include <iostream>

using namespace std;

#define ll long long

class customer{
public:
	ll arrival;
	ll lowerTemp;
	ll upperTemp;
};

bool possible(customer a[], ll init, ll size){
	ll MaxT, MinT, time=0;
	MaxT = MinT = init;

	for(int i=0; i<size; i++){
		MinT -= (a[i].arrival - time);
		MaxT += (a[i].arrival - time);

		if(a[i].upperTemp < MinT || a[i].lowerTemp > MaxT){
			return false;
		}

		MinT = max( MinT, a[i].lowerTemp);
		MaxT = min( MaxT, a[i].upperTemp);
		time = a[i].arrival;
	}
	return true;
}

int main(){
	ll t, n, initialTemp;
	customer a[100];
	cin>>t;
	while(t--){
		cin>>n;
		cin>>initialTemp;

		for(int i=0; i<n; i++){
			cin>>a[i].arrival>>a[i].lowerTemp>>a[i].upperTemp;
		}

		if(possible(a, initialTemp, n)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	} 
}