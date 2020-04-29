class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	int j=0;
    	stack<int> s;
    	for(int i=0; i<pushed.size(); i++){
    		if(!s.empty()){
    			while(!s.empty() && s.top()==popped[j]){
    				s.pop();
                    j++;
    			}
    		}
    		s.push(pushed[i]);
    	}
    	for(j; j<popped.size(); j++){
    		if(s.empty() || s.top()!=popped[j]){
    			return false;
    		}
    		s.pop();
    	}
        return true;
    }
};