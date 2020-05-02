bool isValid(string S){
	char temp;
	stack<char> s;
	for(auto x:S){
		if(s.empty()){
			s.push(x);
		}
		else{
			if(x=='c'){
				temp=s.top();
				s.pop();
				if(!s.empty()&&s.top()=='a'&&temp=='b'){
					s.pop()
				}
				else{
					s.push(temp);
					s.push(x);
				}
			}
			else{
				s.push(x);
			}
		}
		return s.size()==0?true:false;
	}
}