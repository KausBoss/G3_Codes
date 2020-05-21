#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n= A.size();
        queue<int> q;
        int ans=0;
        for(int i=0; i<n; i++){
        	if(A[i] != ((q.size()%2)?0:1) ){
        		ans++;
        		q.push(i+K-1);
        	}
        	while(!q.empty() && q.front() <= i){
        		q.pop();
        	}
        }
        return q.empty() ? ans : -1;
    }
}; 

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        int ret = Solution().minKBitFlips(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}