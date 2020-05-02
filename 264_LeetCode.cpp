#include <bits/stdc++.h>

using namespace std;
#define ll long long

int nthUglyNumber(int n) {
    if(n==1){return n;}
    map<int,int> m;
    priority_queue<int,vector<int>, greater<int>> p;
    p.push(2);p.push(3);p.push(5);
    m[2]=2;m[3]=3;m[5]=5;
    int i=1;
    while(i<n){
    	cout<<p.top()<<" ";
    	int x=p.top();
    	p.pop();
    	if(m.count(2*x)==0){
    		x *=2;
    		m[x]=x;
    		p.push(x);
    	}
    	else if(m.count(3*x)==0){
    		x *=3;
    		m[x]=x;
    		p.push(x);
    	}
    	else{
    		x *=5;
    		m[x]=x;
    		p.push(x);
    	}
    	i++;
    }
    return p.top();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<nthUglyNumber(10);
}