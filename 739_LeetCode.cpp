class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<pair<int, int>> s;
        for(int i=0; i<T.size(); i++){
            if(s.empty()){
                s.push(make_pair(T[i], i));
            }
            else{
                while(!s.empty() && s.top().first<T[i]){
                    ans[s.top().second]=i-s.top().second;
                    s.pop();
                }
                s.push(make_pair(T[i], i));
            }
        }
        return ans;
    }
};