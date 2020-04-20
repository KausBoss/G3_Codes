#include<iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	ll n, l, a[1002]={0}, diff=0;
	cin>>n>>l;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	a[n+1]=l;
	sort(a, a+n+2);
	//for(int i=0; i<=n+1; i++){cout<<a[i]<<"--";}
	//cout<<"\n";

	for(int i=1; i<=n+1; i++){
		diff= max(diff, a[i]-a[i-1]);
	}
	double first = a[1]-a[0];
	double last = a[n+1]-a[n];
	//cout<<first<<" "<<last<<"**";
	double ans ;
	ans = max((double)diff/(double)2., max(first, last));
	//cout<<diff<<endl;
	//double ans=(double)diff/(double)2;
	//cout<< setprecision(8)<< (double)diff/(double)2.<<"\n";
	printf("%.10f\n",(double)ans);
}