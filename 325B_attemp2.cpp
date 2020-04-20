//Code for Stadium and Games

#include<bits/stdc++.h>

using namespace std;
#define int     long long int
#define MX      LLONG_MAX
#define T       int tc;cin>>tc;while(tc--)

int32_t main(){

    int n;cin>>n;
    set<int>x;
    for(int i=0;i<63;i++){
    	int k=pow(2,i)-1;
    	int s=0,e=1e10;
    	if(n==k){
    		x.insert(k+1);continue;
    	}
    	while(s<=e){
    		int t=0;
    		int m=(s+e)/2;
    		t=m;t*=(m-1);t/=2;int p=k;

    		if(p!=0&&m>MX/p)t=MX;
    		else t=t+m*p;
    
    		if(t==n){if(m%2==1)x.insert(m*(k+1));break;}
    		if(t>n)e=m-1;
    		if(t<n)s=m+1;
    	}
    }
    if(x.size()==0){cout<<-1;}
    else{
    	for(auto a:x)cout<<a<<"\n";
    }

}