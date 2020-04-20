#include <bits/stdc++.h>

using namespace std;

bool check(char *ch){
	stack<char> st;
	for(int i=0; ch[i]!='\0'; i++){
		//cout<<ch[i]<<" "<<st.top()<<endl;
		if(ch[i]=='[' || ch[i]=='{' || ch[i]=='('){
			st.push(ch[i]);
		}
		else if(ch[i]==']'){
			if(st.top()=='['){
				st.pop();
			}
			else{return false;}
		} 
		else if(ch[i]=='}'){
			if(st.top()=='{'){
				st.pop();
			}
			else{return false;}
		}
		else if(ch[i]==')'){
			if(st.top()=='('){
				st.pop();
			}
			else{return false;}
		}
	}
	if(st.empty()){return true;}
	else{
		return false;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	char ch[1000];
	cin>>ch;
	if(check(ch)){cout<<"true";}
	else{cout<<"false";}
	
}