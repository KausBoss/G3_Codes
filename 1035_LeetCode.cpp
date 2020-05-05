#include <bits/stdc++.h>

using namespace std;
#define ll long long
map<pair<int, int>, int> m;


int cross(vector<int> A, vector<int> B, int i, int s){
	//base case
	if(i==A.size()){return 0;}
	if(s==B.size()){return 0;}
	//recursive case
	if(m.count(make_pair(i,s))){return m[make_pair(i,s)];}

	int op1=INT_MIN;
	int id=-1;
	for(int j=s; j<B.size(); j++){
		if(B[j] == A[i]){
			id=j;
			break;
		}
	}
	if(id!=-1){
		cout<<"val of "<<A[i]<<" and i: "<<i<<" making pair with j: "<<id<<endl;
		op1 = 1 + cross(A, B, i+1, id+1);
	}
	int op2= cross(A,B, i+1, s);

	m[make_pair(i,s)]=max(op1,op2);
	return max(op1, op2);
}

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    return cross(A, B, 0, 0);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> A{2,5,1,2,5};
	vector<int> B{10,5,2,1,5,2};
	cout<<maxUncrossedLines(A,B);
}
	
