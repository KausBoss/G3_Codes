class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& S) {
        vector<int> ans(S.size(), -1);
        stack<pair<int, int>> s;
        for(int i=0; i<S.size(); i++){
        	if(s.empty()){
        		s.push(make_pair(S[i], i));
        	}
        	else{
        		while(!s.empty()&&S[i]>s.top().first){
        			ans[s.top().second]=S[i];
        			s.pop();
        		}
        		s.push(make_pair(S[i], i));
        	}
        }
        for(int i=0; !s.empty()&&i<s.top().second; i++){
        	while(!s.empty()&&S[i]>s.top().first){
    			ans[s.top().second]=S[i];
    			s.pop();
        	}
        }
        return ans;
    }
};