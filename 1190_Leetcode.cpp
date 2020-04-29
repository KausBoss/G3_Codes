class Solution {
public:
    string reverseParentheses(string S) {
        string t="";
        deque<char> s;
        for(auto x:S){
        	if(x==')'){
        		while(s.back()!='('){
        			t += s.back();
        			s.pop_back();
        		}
        		s.pop_back();
        		for(auto y:t){
        			s.push_back(y);
        		}
        		t = "";
        	}
        	else{
        		s.push_back(x);
        	}
        }
        t = "";
        while(!s.empty()){
        	t += s.front();
        	s.pop_front();
        }
        return t;
    }
};