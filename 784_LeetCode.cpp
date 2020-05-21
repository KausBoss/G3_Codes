class Solution {
public:
	vector<string> ans;
	void permute(int i, string S){
		//base case
		if(i == S.length()){ans.push_back(S);return;}
		//recursive case
		permute(i+1, S);
		if(isalpha(S[i])){ S[i] ^=32; permute(i+1, S);
		}
	}
    vector<string> letterCasePermutation(string S) {
    	permute(0, S);
    	return ans;
    }
};