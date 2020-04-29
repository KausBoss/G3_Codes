class Solution {
	struct mad{
		bool operator() (pair<int,string> const &a, pair<int,string> const &b){
			if(a.first==b.first){
                return a.second<b.second;
            }
			return a.first>b.first;
		}
	};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    	map<string, int> m;
        priority_queue<pair<int,string>,vector<pair<int,string>>, mad> p;
        for(auto x:words){
        	if(m.count(x)){m[x]++;}
        	else{m[x]=1;}
        }

        for(auto x:m){
        	p.push(make_pair(x.second, x.first));
        	if(p.size() > k){
        		p.pop();
        	}
        }
        vector<string> v(p.size());
        int i=p.size()-1;
        while(!p.empty()){
        	v[i--]=p.top().second;
        	p.pop();
        }
        return v;
    }
};