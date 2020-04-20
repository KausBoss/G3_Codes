#include <bits/stdc++.h>

using namespace std;
#define ll long long

int ans=0;
void func(vector<int> &A, int i){
    //checking for squareful
    if(i>1){
        int num = sqrt(A[i-1]+A[i-2]);
        if(A[i-1]+A[i-2] != num*num){
            return;
        }
    }
    //base case
    if(i == A.size()){
    	for(int i=0; i<A.size(); i++){cout<<A[i];}
    	cout<<endl;
        ans++;
        return;
    }
    //recursive case
    for(int j=i; j<A.size(); j++){
        if(j==i || A[j]!=A[i]&& A[j]!=A[j-1]){
            swap(A[j], A[i]);
            func(A, i+1);
            swap(A[j], A[i]);
        }
    }
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{1,1,8,1,8};
	sort(v.begin(), v.end());
	//for(int i=0; i<v.size(); i++){cout<<v[i];}
    //cout<<endl;
	func(v, 0);
	cout<<ans;
}