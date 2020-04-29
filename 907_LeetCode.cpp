#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

int sumSubarrayMins(vector<int> A) {
    stack<int> s;
    int left[A.size()], right[A.size()], n=A.size();
    for(int i=0; i<n; i++){
        while(!s.empty() && A[s.top()]>A[i]){
            s.pop();
        }
        left[i]= s.empty()?i+1:(i-s.top());
        s.push(i);
    }
    for(auto x:left){cout<<x<<" "; }
    s= stack<int>();//clearing the stack

    for(int i=n-1; i>=0; i--){
         while(!s.empty() && A[s.top()]>=A[i]){
            s.pop();
        }
        right[i]= s.empty()?(n-i):(s.top()-i);
        s.push(i);
    }
    cout<<endl;
    for(auto x:right){cout<<x<<" ";}
    int ans =0;
    for(int i=0; i<n; i++){
        ans += ((left[i]%mod)*(right[i]%mod)*(A[i]%mod))%mod;
        ans %=mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> v{71,55,82,55};
    for(auto x:v){cout<<x<<" ";}
    cout<<endl;
    cout<<sumSubarrayMins(v);
}
