class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> q;
        for(auto x:S){
            if(q.empty()){
                q.push_back(x);
            }
            else{
                if(x == q.back()){
                    q.pop_back();
                }
                else{
                    q.push_back(x);
                }
            }
        }
        string ans="";
        while(!q.empty()){
            ans += q.front();
            q.pop_front();
        }
        return ans;
    }
};