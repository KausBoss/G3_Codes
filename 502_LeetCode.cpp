class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    	multiset<pair<int,int>> s;
    	priority_queue<pair<int,int>> p;
    	int n=Capital.size();
    	for(int i=0; i<n; i++){
    		s.insert({Capital[i], Profits[i]});
    	}
    	int ans=W;
        auto it = s.begin();
    	while(k--){
    		//p = priority_queue<pair<int,int>> ();
    		//for(auto it=s.begin(); (it!=s.end()) && ((it->first)<=W); it++){
            while((it!=s.end()) && ((it->first)<=W)){
                pair<int,int> temp = *it;
    			p.push({temp.second, (temp.first)});
                it++;
            }    
    			// pair<int,int> temp = *it;
    			// p.push({temp.second, (temp.first)});
    		//}
            if(p.empty()){return ans;}
    		ans += p.top().first;
            //cout<<p.top().first<<" "<<p.top().second<<endl;
    		W +=p.top().first ;//- p.top().second);
    		s.erase({p.top().second, p.top().first});
            p.pop();
    	}
    	return ans;
    }
};