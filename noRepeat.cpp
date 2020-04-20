#include <bits/stdc++.h>

using namespace std;

int func(string s) {
    map<char, int> m;
    int n=s.length();
    int sz=0, ans=0, last=-1;
    for(int i=0; i<n; i++){
        if(m.count(s[i])==0){
            sz++;
        }
        else{
            if(m[s[i]] >= last){
                last = m[s[i]]+1;
                sz = i - m[s[i]];
            }
            else{ sz++;}
        }
        cout<<i<<" "<<last<<" "<<sz<<" \n";
        m[s[i]] = i;
        ans = max(sz, ans);
    }
    return ans;
}

int main(){
    string s="abcabcbb";
    cout<<func(s);
}