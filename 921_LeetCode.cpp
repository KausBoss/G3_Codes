class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for(auto x:S){
        	if(x=='('){
        		s.push('(');
        	}
        	else{
        		if(s.empty() || s.top()==')'){
        			s.push(')');
        		}
        		else if(s.top()=='('){
        			s.pop();
        		}
        	}
        }
        return s.size();
    }
};