#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ll long long int

ll maxx(ll a, ll b){
	return a>b?a:b;
}

ll MaxArea(int* a, ll n){
	if(n<=0){
		return 0;
	}
	ll area=0, i, height;
	stack<ll> s;

	for(i=0; i<n;){
		if(!s.empty() && a[i] <= a[s.top()]){
			height= a[s.top()];
			s.pop();
			if(s.empty()){
				area = maxx(area, height*i);
				//cout<<area<<"+";
			}
			else{
				area = max(area, height*(i-s.top()-1));
				//cout<<area<<"!";
			}
		}
		else{
			s.push(i++);
		}
	}

	while(!s.empty()){
		height=a[s.top()];
		s.pop();
		if(s.empty()){
			area = maxx(height*i, area);
			//cout<<area<<"#";
		}
		else{
			area = maxx(area, height*(i-s.top()-1));
			//cout<<area<<"%";
		}
	}
	return area;
}

int main(){
	ll n, temp;
	cin>>n;
	while(n!=0){
		int a[200001]={0};
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		cout<<MaxArea(a, n)<<endl;
		cin>>n;
	}
}