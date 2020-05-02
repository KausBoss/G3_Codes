#include <bits/stdc++.h>

using namespace std;
#define ll long long

void tansfer(stack<int> &a, stack<int> &b){
	while(!a.empty()){
		b.push(a.top());
		a.pop();
	}
}

void printTransfer(stack<int> &a, stack<int> &b){
	while(!a.empty()){
		cout<<a.top()<<" ";
		b.push(a.top());
		a.pop();
	}
	//cout<<endl;
}

int scoreOfParentheses(string S) {
    int t1, t2, ans=0;
    stack<int> s;
    stack<int> aux;
    for(auto x:S){
    	if(s.empty()){
    		s.push(0);
    	}
    	else{
    		if(x==')'){
    			t1= s.top()?s.top():1;
    			s.pop();
    			//ans+=t1;
    			if(s.empty()){ans+=t1;}
    			if(!s.empty()){
    				t2=s.top();
    				s.pop();
    				s.push(t2 + 2*t1);
    			}
    		}
    		else{
    			s.push(0);
    		}
    	}
    	cout<<ans<<"---";
    	cout<<x<<" ";
    	if(!s.empty()){
    		tansfer(s, aux);
    		printTransfer(aux, s);
    	} 
    	cout<<endl;
    }
    return  ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s="(((((()())()(()()((()))())))))";
	cout<<scoreOfParentheses(s);
}
