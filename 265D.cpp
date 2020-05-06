#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define inf (int)1e5
int n, a[inf];
map<pair<int,int>, int> m, fact;

int gdc(int a, int b){
	return b==0?a:gdc(b,a%b);
}


int func(vector<int> v, int i){
	//base case
	if(i==n){
		return 0;
	}
	//recursive case
	if(m.count(make_pair(i, v.empty()?0:v.back()))){ return m[make_pair(i, v.empty()?0:v.back())];}
	
	int f=0;
	if(!v.empty()){
		if(fact.count(make_pair(a[i],v.back()))==0){
			fact[make_pair(a[i],v.back())] = gdc(a[i],v.back());
		}
		f=fact[make_pair(a[i],v.back())];
	}


	int op1=func(v, i+1);
	if(!v.empty()&& f<=1){
		m[make_pair(i, v.back())] = op1;
		return op1;
	}

	v.push_back(a[i]);
	int op2= 1+ func(v, i+1);
	v.pop_back();
	//cout<<i<<" "<<a[i]<<" "<<max(op1,op2)<<endl;
	m[make_pair(i, v.empty()?0:v.back())] = max(op1, op2);
	return max(op1, op2);
}

// int func(vector<int> v, int i){
// 	//base case
// 	if(i==n){
// 		return 0;
// 	}
// 	//recursive case
// 	if(m.count(make_pair(i, v.empty()?0:v.back()))){ return m[make_pair(i, v.empty()?0:v.back())];}


// 	int op1=func(v, i+1);
// 	v.push_back(a[i]);
// 	int op2= 1+ func(v, i+1);
// 	v.pop_back();
// 	if(v.empty() || gdc(a[i], v.back())>1){
// 		//cout<<i<<" "<<a[i]<<" "<<max(op1,op2)<<endl;
// 		m[make_pair(i, v.empty()?0:v.back())] = max(op1, op2);
// 		return max(op1, op2);
// 	}
// 	else{
// 		//cout<<i<<" "<<v.back()<<" "<<op1<<" not choose "<<a[i]<<endl;
// 		m[make_pair(i, v.empty()?0:v.back())] = op1;
// 		return op1;
// 	}
// }

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a, a+n);
	vector<int> v;
	cout<<func(v, 0);
}